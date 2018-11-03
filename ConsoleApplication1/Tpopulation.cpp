#include "stdafx.h"
#include "Tpopulation.h"


Tpopulation::Tpopulation(){}

void Tpopulation::genererPopulation(char * nomFichier)
{

	Tvecteur vecteur;

	Tprobleme prob(nomFichier);
	prob.lireFichier();

	int n = prob.getN();
	int m = prob.getM();

	int debutDicho;
	int finDicho;
	int milieu;

	int coutTmp;

	/** Tirage de 100 vecteurs différents au hasard **/
	// Le 1er :

	vecteur.construireV(n, m);
	liste[0] = vecteur;
	prob.setVecteur(vecteur);
	Tsolution S(prob);
	S.evaluer();
	vecteur = S.rechercheLocale();
	liste[0] = vecteur;
	coutListe[0] = S.getCoutSolution();

	tableHash[vecteur.toString()] = 1; //Insertion dans la table de hashage

	//Tirage des autres
	for (int i = 1; i < TAILLEPOP; i++) {
		do {
			vecteur.construireV(n, m);
		} while (testerDouble(vecteur)); //On construit un vecteur tant qu'il a un doublon dans la population

		//Calcul du cout :
		//liste[i] = vecteur;

		prob.setVecteur(vecteur);
		Tsolution S(prob);
		S.evaluer();
		vecteur = S.rechercheLocale();
		coutTmp = S.getCoutSolution();

		tableHash[vecteur.toString()] = 1; //Insertion dasn la table de hachage

		/** Insertion par dichotomie **/

		debutDicho = 0;
		finDicho = i;
		while (debutDicho < finDicho) {
			milieu = (debutDicho + finDicho) / 2;
			if (coutTmp <= coutListe[m]) finDicho = milieu;
			else debutDicho = milieu + 1;
		}
		//décalage à droite
		for (int k = i; k > debutDicho; k--) { // on part de la droite -> gauche
			coutListe[k] = coutListe[k - 1];
			liste[k] = liste[k - 1];
		}
		coutListe[debutDicho] = coutTmp;
		liste[debutDicho] = vecteur;
	}
	int test = 0;
}

void Tpopulation::genererFils() {

}

void Tpopulation::afficherPopulation(ostream& flux) {
	flux << "[Vecteur Birwirth]\t[cout]\n" << std::endl;
	for (int i = 0; i < TAILLEPOP; i++) {
		flux << liste[i].toString() << "\t" << coutListe[i] << std::endl;
	}

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
	bool test = tableHash[vec.toString()];
	return test;

}


