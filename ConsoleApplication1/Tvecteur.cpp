#include "stdafx.h"
#include "Tvecteur.h"
#include "Tprobleme.h"
#include <cstdlib>
#include <ctime> 


Tvecteur::Tvecteur()
{
}

void Tvecteur::construireV(int n, int m) {
	
	int decompteRessources[TAILLENETMMAX][2];
	int nombreAleatoire = 0;
	int tailleReelle = n;

	tailleVecteur = n*m;

	for (int i = 0; i < n; i++) {
		decompteRessources[i][0] = m;
		decompteRessources[i][1] = i;
	}

	for (int i = 0; i < n*m; i++) {

		nombreAleatoire = rand()%tailleReelle;

		decompteRessources[nombreAleatoire][0]--;
		V[i] = decompteRessources[nombreAleatoire][1];

		if (decompteRessources[nombreAleatoire][0] == 0) { // suppression par écrasement
			decompteRessources[nombreAleatoire][0] = decompteRessources[tailleReelle-1][0];
			decompteRessources[nombreAleatoire][1] = decompteRessources[tailleReelle-1][1];
			tailleReelle--;
		}

	}


}

int Tvecteur::trouveriEmeApparition(int numPiece, int i) {
	int cpt = 0;
	int y = 0;

	for (y = 0; cpt != i; y++) {
		if (V[y] == numPiece)
			cpt++;
	}

	return y-1;

}

int * Tvecteur::getVecteur()
{
	return V;
}

int Tvecteur::getTailleVecteur()
{
	return tailleVecteur;
}


void Tvecteur::setListe(int vec[TAILLEVECMAX])
{
	int i = 0;
	while (i < TAILLEVECMAX) {
		V[i] = vec[i];
		i++;
	}
}

void Tvecteur::setTaille(int taille)
{
	tailleVecteur = taille;
}

std::string Tvecteur::toString()
{
	std::string tmp = "";

	for (int i = 0; i < tailleVecteur; i++) {
		tmp += std::to_string(V[i]);
	}

	return tmp;
}
