#include "stdafx.h"
#include "Tprobleme.h"

using namespace System;

Tprobleme::Tprobleme(string nomFic):nomFic(nomFic)
{
	Tvecteur vec;
	vecteur = vec;
}

void Tprobleme::lireFichier() {

	ifstream fichier;

	fichier.open(nomFic);

	if (!fichier.fail()) {

		fichier >> n;
		fichier >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				fichier >> mach[i][j];
				fichier >> poids[i][j];
			}
		}

		fichier.close();

	}

}

void Tprobleme::construireVecteur() //Pourrait etre inclus dans le constructeur
{
	vecteur.construireV(n, m);
}

void Tprobleme::afficherProbleme()
{
	Console::WriteLine("[mach] :\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Console::Write(mach[i][j]+1 + "\t"); //Affichage de M sur la console
		}
		Console::Write("\n");
	}

	Console::WriteLine("[poids] :\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Console::Write(poids[i][j]+ "\t"); //Affichage de P sur la console
		}
		Console::Write("\n");
	}

	Console::WriteLine("[Vecteur de Bierwirth] :\n");
	for (int i = 0; i < n*m; i++) {
		Console::Write(vecteur.getVecteur()[i]+1 + "\t"); //Affichage de V sur la console
	}
	cout << endl;

}

int Tprobleme::trouveriEmeApparitionVecteur(int numPiece, int i)
{

	return vecteur.trouveriEmeApparition(numPiece, i);
}



int Tprobleme::getM()
{
	return m;
}


int Tprobleme::getN()
{
	return n;
}

void Tprobleme::setVecteur(int vec[TAILLEVECMAX])
{
	vecteur.setListe(vec);
}

void Tprobleme::setVecteur(Tvecteur vec)
{
	vecteur = vec;
}

int * Tprobleme::getVecteur()
{
	return vecteur.getVecteur();
}

 
int** Tprobleme::getMach()
{
	int ** machCopie;

	machCopie = (int**)malloc(sizeof(int*)*TAILLENETMMAX);
	for (int i = 0; i<TAILLENETMMAX; i++)
		machCopie[i] = (int*)malloc(sizeof(int)*TAILLENETMMAX);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			machCopie[i][j] = mach[i][j];

		}
	}

	return machCopie;
}

int** Tprobleme::getPoids()
{
	int ** poidsCopie;

	poidsCopie = (int**)malloc(sizeof(int*)*TAILLENETMMAX);
	for (int i = 0; i<TAILLENETMMAX; i++)
		poidsCopie[i] = (int*)malloc(sizeof(int)*TAILLENETMMAX);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			poidsCopie[i][j] = poids[i][j];

		}
	}

	return poidsCopie;
}

Tvecteur Tprobleme::getVecteurObj()
{
	return vecteur;
}


