#pragma once
#include "Tvecteur.h"
#include <iostream>
#include <fstream>

using namespace std;

const int nmax = 30 ;
const int mmax = 30 ;

class Tprobleme
{

private: 
	int n; //nb de pièces
	int m; //nb de machines (ressources)

	int mach[nmax][mmax]; //On considere que la premiere piece est la piece 0
	int poids[nmax][mmax];

	Tvecteur vecteur;
	string nomFic;

public:
	Tprobleme(string);
	void lireFichier();
	void construireVecteur();
	void afficherProbleme();
	int trouveriEmeApparitionVecteur(int, int);
	int getM();
	int getN();
	
	void setVecteur(int[vmax]);
	void setVecteur(Tvecteur);

	int * getVecteur();
	int ** getMach();
	int ** getPoids();
};