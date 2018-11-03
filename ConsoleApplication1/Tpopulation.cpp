#include "stdafx.h"
#include "Tpopulation.h"

Tpopulation::Tpopulation(char * nomFic):probleme(Tprobleme(nomFic)){
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

		tableHash.insert({vecteur.toString(), 1}); //Insertion dasn la table de hachage

		//Insertion dans la population
		insertionTrie(vecteur, coutTmp, 0, i);
	}
}

void Tpopulation::genererFils() {
	Tvecteur vecFils;
	Tvecteur parent1, parent2;

	int vecFilsBrut[TAILLEVECMAX];
	int *vecParent1, *vecParent2;
	int tailleVec;
	int rand1, rand2;
	int randpos;
	int cpt;

	int decompteRessources[TAILLENETMMAX]; //Pour suivre le nombre de passage par machine 

	for (int i = 0; i < n; i++) {
		decompteRessources[i] = m;
	}


	rand1 = rand() % (TAILLEPOP - 10); //Nombre aleatoire entre 0 et TAILLEPOP-10
	rand2 = rand() % 10 + (TAILLEPOP-10); //Nombre aleatoire entre TAILLEPOP-10 et TAILLEPOP

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

	for (int k = cpt; cpt < tailleVec; k = (k+1) % tailleVec) { //Genetique du parent 2
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
	Tsolution S(probleme);
	S.evaluer();
	vecFils = S.rechercheLocale();

	/* Test d'ajout dans la population */

	if (!testerDouble(vecFils)) { //Si il n'existe pas deja
		randpos = rand() % 1;
		if (randpos == 1)
			ecraserElem(rand1);
		else
			ecraserElem(rand2);
		insertionTrie(vecFils, S.getCoutSolution(), 0, TAILLEPOP-1);
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
	for (int k = pos; k < TAILLEPOP-1; k++) {
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

/* testerDouble
@return : bool, true si il existe deja dans la population
				false sinon
*/
bool Tpopulation::testerDouble(Tvecteur vec) {
	std::unordered_map<std::string, int>::iterator it;
	it = tableHash.find(vec.toString());
	return it != tableHash.end();
}


