#include "stdafx.h"
#include "Tpopulation.h"

Tpopulation::Tpopulation() {}


Tpopulation::Tpopulation(char * nomFichier)
{/*
	Tvecteur vecteur;

	Tprobleme prob(nomFichier);
	prob.lireFichier();

	Tsolution S;

	int n = prob.getN();
	int m = prob.getM();

	int debutDicho;
	int finDicho;
	int milieu;

	Tvecteur vecTps;
	int coutTps;
	*/
	/** Tirage de 100 vecteurs différents au hasard **/
	/*
	// Le 1er :
	  vecteur.construireV(n, m);
	  liste[0] = vecteur;
	  prob.setVecteur(liste[0]);
	  S.getProbleme = prob;
	  coutListe[0] = S.evaluer();
	//  A FAIRE : le rentrer dans la table de hachage

	for (int i = 1; i < 100; i++) {
		do {
			vecteur.construireV(n, m);
		} while (tableHash[vecteur] == 1); // A FAIRE

		vecTps = vecteur;
		
		*/
		/** Calcul du coût **/
		/*
		prob.setVecteur(liste[i]);
		S.getProbleme = prob;
		coutTps = S.evaluer();

		debutDicho = 0;
		finDicho = i;
		while (debutDicho < finDicho) {
			milieu = (debutDicho + finDicho) / 2;
			if (coutTps < coutListe[m]) finDicho = milieu--;
			else debutDicho = milieu++;
		}
		//décalage à droite
		for (int k = i+1; k > debutDicho; k--) { // on part de la droite -> gauche
			coutListe[k] = coutListe[k-1];
			liste[k] = liste[k - 1];
		}
		coutListe[debutDicho] = coutTps;
		liste[debutDicho] = vecTps;
	}

	         g, d, m: entier;
	g<- 0; d <- n-1 ;
	Tant_que(g<=d) faire
	         m<- (g+d)/2;
	         if (a < t[m]) alors  d<- m-1;
	                	else g <-m+1 ;
                  fin_if;
	          insere(t,n,a,g);
        fin_tant_que
		*/




}

Tvecteur * Tpopulation::getListe()
{
	return liste;
}


void Tpopulation::genetique(int r)
{

}
