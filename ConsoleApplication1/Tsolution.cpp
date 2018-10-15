#include "stdafx.h"
#include "Tsolution.h"


Tsolution::Tsolution(Tprobleme prob):probleme(prob)
{
}


int Tsolution::evaluer()
{
	int T[nmax][mmax];
	int pOrdre[nmax][mmax];
	int ** P; 
	int np[mmax];
	int m[mmax];
	int cpt;
	int piece; // k cf cours
	int machine;
	int prec;
	int date;
	int max;
	int k;
	int p;

	/* Initialisation */

	P = probleme.getPoids();
	cpt = 0;

	for (int i = 0; i < probleme.getN(); i++) {
		for (int j = 0; j < probleme.getM(); j++) {
			T[i][j] = cpt;
			ES[cpt] = 0;									// Init ES a 0
			pOrdre[i][j] = P[i][probleme.getMach()[i][j]];	// Init P ordonnee
			cpt++;
			
		}
	}

	for (int i = 0; i < probleme.getM(); i++) {
		m[i] = -1;
	}

	for (int i = 0; i < probleme.getN(); i++) {
		np[i] = 0;
	}
	

	/* Fin Ini (qui marche) */
	cpt--;
	for (int i = 0; i <= cpt; i++) {
		piece = probleme.getVecteur()[i];
		np[piece] = np[piece] + 1;


		if (np[piece] > 1) { // arc horizontal
			prec = ES[ T[piece][np[piece]-2] ];
			date = prec + P[piece][np[piece]-2];

			if (date > ES[T[piece][np[piece]-1]]) 
				ES[T[piece][np[piece]-1]] = date;

		}
		machine = probleme.getMach()[piece][np[piece]-1];

		if (m[machine] > -1) { //disfonction
			prec = ES[m[machine]];
			if (prec + pOrdre[m[machine]][machine] > ES[T[piece][np[piece]-1]]) 
				ES[T[piece][np[piece]-1]] = prec + pOrdre[m[machine]][machine]; 
		}
		m[machine] = piece;

	}

	
	max = ES[probleme.getM()-1] + P[0][probleme.getM() - 1]; // on place le max direct à la date de fin de la pièce 0

	p = 1; // p et k sont des compteurs pour calculer les dates de fin des pièces 1 à NbPièce-1
	k = (probleme.getM() - 1) + probleme.getM();

	while (p <= probleme.getN()) {
		if (ES[k] + P[p][probleme.getM()-1] > max) {
			max = ES[k] + P[p][probleme.getM() - 1];
		 }
		p++;
		k += probleme.getM();
	}

	return max;
}

void Tsolution::afficherSolution()
{
	int cpt = 0;
	cout << "\n[ES] : ";
	for (int i = 0; i < probleme.getN(); i++) {
		for (int j = 0; j < probleme.getM(); j++) {
			cout << ES[cpt] << " ";
			cpt++;
		}
		cout << " | ";
	}
	cout << endl;
}


