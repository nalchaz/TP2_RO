#pragma once
#include "Tvecteur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define TAILLENETMMAX 30
using namespace std;

class Tprobleme
{

private: 
	int n; //nb de pièces
	int m; //nb de machines (ressources)

	int mach[TAILLENETMMAX][TAILLENETMMAX]; //On considere que la premiere piece est la piece 0
	int poids[TAILLENETMMAX][TAILLENETMMAX];

	Tvecteur vecteur;
	string nomFic;

public:
	Tprobleme();
	Tprobleme(string);
	void lireFichier();
	void construireVecteur();
	void afficherProbleme(ostream&);
	string toString();
	int trouveriEmeApparitionVecteur(int, int);
	int getM();
	int getN();
	
	void setVecteur(int[TAILLEVECMAX]);
	void setVecteur(Tvecteur);

	int * getVecteur();
	int ** getMach();
	int getMach(int, int);
	int ** getPoids();
	Tvecteur getVecteurObj();
};