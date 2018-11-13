#include "stdafx.h"
#include "Tpopulation.h"

Tpopulation::Tpopulation()
{
}

Tpopulation::Tpopulation(char * nomFic) :probleme(Tprobleme(nomFic)) {
	probleme.lireFichier();
}

Tpopulation::Tpopulation(string nomFic) : probleme(Tprobleme(nomFic.c_str())) {
	probleme.lireFichier();
}

void Tpopulation::genererPopulation()
{

	Tvecteur vecteur;

	n = probleme.getN();
	m = probleme.getM();

	int coutTmp;

	/** Tirage de 100 vecteurs différents au hasard **/
	// Le 1er :

	vecteur.construireV(n, m);
	liste[0] = vecteur;
	probleme.setVecteur(vecteur);
	Tsolution S(probleme);
	S.evaluer();
	vecteur = S.rechercheLocale();
	liste[0] = vecteur;
	coutListe[0] = S.getCoutSolution();

	tableHash.insert({ vecteur.toString(), 1 }); //Insertion dans la table de hashage

	//Tirage des autres
	for (int i = 1; i < TAILLEPOP; i++) {
		do {
			vecteur.construireV(n, m);
		} while (testerDouble(vecteur)); //On construit un vecteur tant qu'il a un doublon dans la population

		//Calcul du cout :
		//liste[i] = vecteur;

		probleme.setVecteur(vecteur);
		Tsolution S(probleme);
		S.evaluer();
		vecteur = S.rechercheLocale();
		coutTmp = S.getCoutSolution();

		tableHash.insert({ vecteur.toString(), 1 }); //Insertion dasn la table de hachage

		//Insertion dans la population
		insertionTrie(vecteur, coutTmp, 0, i);
	}
}

Tsolution Tpopulation::genererFils() {
	Tvecteur vecFils;
	Tvecteur parent1, parent2;
	Tsolution S;

	int vecFilsBrut[TAILLEVECMAX];
	int *vecParent1, *vecParent2;
	int tailleVec;
	int rand1, rand2;
	int randpos;
	int cpt;

	int decompteRessources[TAILLENETMMAX]; //Pour suivre le nombre de passage par machine 

	do {
		for (int i = 0; i < n; i++) {
			decompteRessources[i] = m;
		}


		rand1 = rand() % (int)(TAILLEPOP - (TAILLEPOP/100.0)*10); //Nombre aleatoire entre 0 et 90% de TAILLEPOP
		rand2 = rand() % (int)((TAILLEPOP / 100.0) * 10) + (int)((TAILLEPOP / 100.0) * 90); //Nombre aleatoire entre 90% de TAILLEPOP et TAILLEPOP

		randpos = rand() % n*m; //Nombre aleatoire entre 0 et la taille du vecteur de Bierwirth

		parent1 = liste[rand1];
		parent2 = liste[rand2];
		vecParent1 = parent1.getVecteur();
		vecParent2 = parent2.getVecteur();
		tailleVec = parent2.getTailleVecteur();

		for (cpt = 0; cpt < randpos; cpt++) { //Genetique du parent 1
			vecFilsBrut[cpt] = vecParent1[cpt];
			decompteRessources[vecParent1[cpt]]--;
		}

		for (int k = cpt; cpt < tailleVec; k = (k + 1) % tailleVec) { //Genetique du parent 2
			while (decompteRessources[vecParent2[k]] == 0)
				k = (k + 1) % tailleVec;
			vecFilsBrut[cpt] = vecParent2[k];
			decompteRessources[vecParent2[k]]--;
			cpt++;
		}

		vecFils.setListe(vecFilsBrut);
		vecFils.setTaille(tailleVec);
		/* Evaluation et recherche locale */

		probleme.setVecteur(vecFils);
		S.setProbleme(probleme);
		S.evaluer();
		vecFils = S.rechercheLocale();

		/* Test d'ajout dans la population */
	} while (testerDouble(vecFils));
	return S;

}

void Tpopulation::generationSuivante()
{
	Tpopulation popFils;
	Tsolution filsCour;
	int * listeCout;
	Tvecteur * listeVec;

	int listeCoutFusion[TAILLEPOP];
	Tvecteur listeVecFusion[TAILLEPOP];
	int i = 0, j = 0, cpt = 0;

	filsCour = genererFils();
	popFils.coutListe[0] = filsCour.getCoutSolution();
	popFils.liste[0] = filsCour.getProbleme().getVecteurObj();
	popFils.hashInsert(filsCour.getProbleme().getVecteurObj());

	for (int i = 1; i < TAILLEPOP / 2; i++) {
		do {
			filsCour = genererFils();
		} while (popFils.testerDouble(filsCour.getProbleme().getVecteurObj()));
		popFils.hashInsert(filsCour.getProbleme().getVecteurObj());
		popFils.insertionTrie(filsCour.getProbleme().getVecteurObj(), filsCour.getCoutSolution(), 0, i);
	}
	listeVec = popFils.getListe();
	listeCout = popFils.getListeCout();

	while(j < TAILLEPOP / 2 && i < TAILLEPOP) { // On insere les fils dans la population
		if (listeCout[i] < coutListe[j])
		{
			listeCoutFusion[cpt] = listeCout[i];
			listeVecFusion[cpt] = listeVec[i];
			cpt++;
			i++;
		}
		else
		{
			listeCoutFusion[cpt] = coutListe[j];
			listeVecFusion[cpt] = liste[j];
			cpt++;
			j++;
		}
	}
	while (cpt < TAILLEPOP) { // On insere le reste de la population
		listeCoutFusion[cpt] = coutListe[j];
		listeVecFusion[cpt] = liste[j];
		cpt++;
		j++;
	}
	for (int i = 0; i < TAILLEPOP; i++) {
		coutListe[i] = listeCoutFusion[i];
		liste[i] = listeVecFusion[i];
	}

}

/** Insertion par dichotomie **/
void Tpopulation::insertionTrie(Tvecteur& vec, int coutSol, int debut, int fin) {

	int milieu;
	int debutDicho = debut;
	int finDicho = fin;

	while (debutDicho < finDicho) {
		milieu = (debutDicho + finDicho) / 2;
		if (coutSol <= coutListe[milieu])
			finDicho = milieu;
		else
			debutDicho = milieu + 1;
	}
	//décalage à droite
	for (int k = fin; k > debutDicho; k--) { // on part de la droite -> gauche
		coutListe[k] = coutListe[k - 1];
		liste[k] = liste[k - 1];
	}
	coutListe[debutDicho] = coutSol;
	liste[debutDicho] = vec;
}

void Tpopulation::ecraserElem(int pos) {

	//décalage à gauche
	for (int k = pos; k < TAILLEPOP - 1; k++) {
		coutListe[k] = coutListe[k + 1];
		liste[k] = liste[k + 1];
	}

}

void Tpopulation::afficherPopulation(ostream& flux) {
	flux << "[Vecteur Bierwirth]\t\t\t[cout]\n" << std::endl;
	for (int i = 0; i < TAILLEPOP; i++) {
		flux << liste[i].toString() << "\t" << coutListe[i] << std::endl;
	}

}

string Tpopulation::toString() {
	std::stringstream ss;
	afficherPopulation(ss);
	return ss.str();
}

Tvecteur * Tpopulation::getListe()
{
	return liste;
}

int * Tpopulation::getListeCout()
{
	return coutListe;
}

void Tpopulation::hashInsert(Tvecteur vec) {
	tableHash.insert({ vec.toString(), 1 });
}
/* testerDouble
@return : bool, true si il existe deja dans la population
				false sinon
*/
bool Tpopulation::testerDouble(Tvecteur vec) {
	std::unordered_map<std::string, int>::iterator it;
	it = tableHash.find(vec.toString());
	return it != tableHash.end();
}


