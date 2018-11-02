#include "stdafx.h"
#include "Tsolution.h"


Tsolution::Tsolution(Tprobleme prob):probleme(prob)
{
}


int Tsolution::evaluer()
{
	int T[nmax][mmax];
	int mOrdre[nmax][mmax];
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
	int position;
	int pereCour;
	int cheminCritique[30 * 30];

	/* Initialisation */

	P = probleme.getPoids();
	cpt = 0;


	for (int i = 0; i < probleme.getN(); i++) {
		for (int j = 0; j < probleme.getM(); j++) {
			T[i][j] = cpt;
			ES[cpt] = 0;							// Init ES a 0
			PERE[cpt] = -1;							// Init PERE a -1
			int  **ma_machine = probleme.getMach();
			int numero_machine = ma_machine[i][j];
			pOrdre[i][numero_machine] = P[i][j];	// Init P ordonnee
			mOrdre[i][probleme.getMach()[i][j]] = j;
			cpt++;		
		}
	}



	for (int i = 0; i < probleme.getM(); i++) {
		m[i] = -1;
		cheminCritique[i] = -1;
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
			position = T[piece][np[piece] - 2];
			prec = ES[ position ];
			date = prec + P[piece][np[piece]-2];

			if (date > ES[T[piece][np[piece] - 1]])
				PERE[T[piece][np[piece]-1]] = position;
				ES[T[piece][np[piece]-1]] = date;

		}
		machine = probleme.getMach()[piece][np[piece]-1];

		if (m[machine] > -1) { // disjonction
			int piece_sur_la_machine = m[machine];
			position = piece_sur_la_machine*probleme.getM() + mOrdre[piece_sur_la_machine][machine];
			prec = ES[position];
			if (prec + pOrdre[piece_sur_la_machine][machine] > ES[T[piece][np[piece] - 1]]) {

				PERE[T[piece][np[piece] - 1]] = position;
				ES[T[piece][np[piece] - 1]] = prec + pOrdre[piece_sur_la_machine][machine];

			}
		}
		m[machine] = piece;

	}

	
	max = ES[probleme.getM()-1] + P[0][probleme.getM() - 1]; // on place le max direct à la date de fin de la pièce 0

	p = 1; // p et k sont des compteurs pour calculer les dates de fin des pièces 1 à NbPièce-1
	k = (probleme.getM() - 1) + probleme.getM();

	pereCour = k;
	while (p <= probleme.getN()) {
		if (ES[k] + P[p][probleme.getM()-1] > max) {
			max = ES[k] + P[p][probleme.getM() - 1];
			pereCour = k;
		 }
		p++;
		k += probleme.getM();
	}
	cheminCritique[0] = pereCour;
	for (cpt = 1; PERE[pereCour] != -1; cpt++) {
		pereCour = PERE[pereCour];
		cheminCritique[cpt] = pereCour;
	}
	setCheminCritique(cheminCritique, cpt);

	return max;
}

void Tsolution::rechercheLocale() {
	int i, j, n;
	int cout;
	int * PERE = getPere();
	Tsolution solution2(probleme);

	n = cheminCritique[0];
	cout = evaluer();
	i = n;
	j = PERE[i];
	
	while ((j != -1) && (n < probleme.getM() * probleme.getN())) {

		if (probleme.getVecteur()[i] != probleme.getVecteur()[j]) { //i et j font ref à des pieces differentes;

		}
	}
	
}

void Tsolution::afficherSolution()
{
	//AFFICHAGE ES
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

	cpt = 0;
	//AFFICHAGE PERE
	cout << "\n[PERE] : ";
	for (int i = 0; i < probleme.getN(); i++) {
		for (int j = 0; j < probleme.getM(); j++) {
			cout << PERE[cpt] << " ";
			cpt++;
		}
		cout << " | ";
	}
	cout << endl;

}

int * Tsolution::getPere()
{
	return PERE;
}

void Tsolution::setCheminCritique(int * chemin, int taille)
{
	for (int i = 0; i < taille; i++) {
		cheminCritique[i] = chemin[i];
	}
}

