#include "stdafx.h"
#include "Tvecteur.h"
#include <cstdlib>
#include <ctime> 


Tvecteur::Tvecteur()
{
}

void Tvecteur::construireV(int n, int m) {
	
	int decompteRessources[30][2];
	int nombreAleatoire = 0;
	int tailleReelle = n;

	srand(time(NULL)); // initialisation de rand

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

int * Tvecteur::getVecteur()
{
	return V;
}

void Tvecteur::setListe(int vec[vmax])
{
	int i = 0;
	while (i < vmax) {
		V[i] = vec[i];
		i++;
	}
}
