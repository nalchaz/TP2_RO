#include "stdafx.h"
#include "Tpopulation.h"


Tpopulation::Tpopulation(char * nomFichier)
{
	
	Tvecteur vecteur;

	Tprobleme prob(nomFichier);
	prob.lireFichier();

	

	int n = prob.getN();
	int m = prob.getM();

	int debutDicho;
	int finDicho;
	int milieu;

	Tvecteur vecTps;
	int coutTps;

	

	/** Tirage de 100 vecteurs différents au hasard **/
	// Le 1er :

	vecteur.construireV(n, m);
	liste[0] = vecteur;
	prob.setVecteur(liste[0]);
	Tsolution S(prob);
	coutListe[0] = S.getCoutSolution();
	
	tableHash[hashVecteur(vecteur)] = 1; //Insertion dans la table de hashage
/*
	for (int i = 1; i < 100; i++) {
		do {
			vecteur.construireV(n, m);
		} while ( == 1); // A FAIRE : voir sil existe déjà -> créer Tester_Double ?

		vecTps = vecteur;


		/** Calcul du coût **/
	/*
		prob.setVecteur(liste[i]);
		S.getProbleme = prob;
		coutTps = S.evaluer();

		/** Insertion par dichotomie **/
	/*
		debutDicho = 0;
		finDicho = i;
		while (debutDicho < finDicho) {
			milieu = (debutDicho + finDicho) / 2;
			if (coutTps <= coutListe[m]) finDicho = milieu;
			else debutDicho = milieu + 1;
		}
		//décalage à droite
		for (int k = i; k > debutDicho; k--) { // on part de la droite -> gauche
			coutListe[k] = coutListe[k - 1];
			liste[k] = liste[k - 1];
		}
		coutListe[debutDicho] = coutTps;
		liste[debutDicho] = vecTps;
	}
*/
	

}

Tvecteur * Tpopulation::getListe()
{
	return liste;
}


void Tpopulation::genetique(int r)
{

}

string hashVecteur(Tvecteur vecteur) {
	std::string tmp = "";
	int * vec = vecteur.getVecteur();
	int taille = vecteur.getTailleVecteur();

	for (int i = 0; i < taille; i++) {
		tmp += std::to_string(vec[i]);
	}

	return tmp;

}
