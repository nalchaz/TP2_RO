#include "stdafx.h"
#include "Tsolution.h"

Tsolution::Tsolution(Tprobleme prob):probleme(prob)
{
}

void Tsolution::prendreValeurs(Tsolution& autreSol)
{
	setES(autreSol.getES());
	setPere(autreSol.getPere());
	setCheminCritique(autreSol.getCheminCritique());
	coutSolution = autreSol.getCoutSolution();
	probleme = autreSol.getProbleme();

}


void Tsolution::evaluer()
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
	int cheminCritique[TAILLEMAX * TAILLEMAX];
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
	cheminCritique[cpt] = -1;
	setCheminCritique(cheminCritique);

	coutSolution = max;
}

/* La solution doit avoir ete evalue pour effectuer une recherche locale*/
Tvecteur Tsolution::rechercheLocale() {
	int i, j, posi, posj, n = 1, cpt = 0;
	int piecei, piecej;
	int nbPassagePiece[TAILLEMAX];
	int posPieceDansBirw[TAILLEMAX];
	int * PERE = getPere();
	int nbMachine = probleme.getM();
	int tmp;

	Tsolution solution2(probleme);

	i = cheminCritique[0];
	j = cheminCritique[1];
	
	for (int k = 0; k < probleme.getN(); k++) {
		nbPassagePiece[k] = nbMachine;
		posPieceDansBirw[k] = probleme.trouveriEmeApparitionVecteur(k, nbMachine);
	}

	 
	while ((j != -1) && (cpt < probleme.getM() * probleme.getN())) {
		piecei = i / nbMachine;
		piecej = j / nbMachine;
		if (piecei != piecej) { //i et j font ref à des pieces differentes;
			posi = posPieceDansBirw[piecei];
			posj = posPieceDansBirw[piecej];
			nbPassagePiece[piecei]--;
			posPieceDansBirw[piecei] = probleme.trouveriEmeApparitionVecteur(piecei, nbPassagePiece[piecei]);
			
			tmp = solution2.probleme.getVecteur()[posi]; //Permutation des operations i et j
			solution2.probleme.getVecteur()[posi] = solution2.probleme.getVecteur()[posj];
			solution2.probleme.getVecteur()[posj] = tmp;
			solution2.evaluer();

			if (solution2.getCoutSolution() < coutSolution) { //Si le cout est inferieur
				prendreValeurs(solution2); //La solution est changé

				/* Reinitialisation des variables pour la recherche locale*/

				i = cheminCritique[0];
				j = cheminCritique[1];
				n = 1;
				for (int k = 0; k < probleme.getN(); k++) {
					nbPassagePiece[k] = nbMachine;
					posPieceDansBirw[k] = probleme.trouveriEmeApparitionVecteur(k, nbMachine);
				}
			}
			else
			{
				n++;
				i = j;
				j = cheminCritique[n];
			}
		}
		else
		{
			n++;
			i = j;
			j = cheminCritique[n];
		}
		cpt++;
	}
	return probleme.getVecteurObj();
}

void Tsolution::afficherSolution(ostream& flux)
{
	//AFFICHAGE ES
	int cpt = 0;
	flux << "\n[ES] : ";
	for (int i = 0; i < probleme.getN(); i++) {
		for (int j = 0; j < probleme.getM(); j++) {
			flux << ES[cpt] << " ";
			cpt++;
		}
		flux << " | ";
	}
	flux << endl;

	cpt = 0;
	//AFFICHAGE PERE
	flux << "\n[PERE] : ";
	for (int i = 0; i < probleme.getN(); i++) {
		for (int j = 0; j < probleme.getM(); j++) {
			flux << PERE[cpt] << " ";
			cpt++;
		}
		flux << " | ";
	}
	flux << endl;

	//AFFICHAGE CHEMIN CRITIQUE
	int i = 0;

	flux << "\n[CHEMIN CRITIQUE] de la D vers la G : ";
	while (cheminCritique[i] != -1) {
		flux << cheminCritique[i] << " ";
		i++;
	}
	flux << endl;

	//AFFICHAGE DU COUT
	flux << "\n[COUT] : " << coutSolution << endl;

}

int * Tsolution::getPere()
{
	return PERE;
}

int * Tsolution::getES()
{
	return ES;
}

int * Tsolution::getCheminCritique()
{
	return cheminCritique;
}

Tprobleme Tsolution::getProbleme()
{
	return probleme;
}

int Tsolution::getCoutSolution()
{
	return coutSolution;
}

void Tsolution::setCheminCritique(int * chemin)
{
	for (int i = 0; i < TAILLEMAX-1; i++) {
		cheminCritique[i] = chemin[i];
	}
}

void Tsolution::setES(int * ESaCopier)
{
	for (int i = 0; i < TAILLEMAX-1; i++) {
		ES[i] = ESaCopier[i];
	}
}

void Tsolution::setPere(int * PereACopier)
{
	for (int i = 0; i < TAILLEMAX-1; i++) {
		PERE[i] = PereACopier[i];
	}
}
