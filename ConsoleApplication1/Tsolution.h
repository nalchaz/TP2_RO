#pragma once
#include "Tprobleme.h"
#include <iostream>
#define TAILLEMAX 30
using namespace std;

class Tsolution
{
private:
	int ES[TAILLEMAX * TAILLEMAX];
	int PERE[TAILLEMAX * TAILLEMAX];
	int cheminCritique[TAILLEMAX * TAILLEMAX];
	int coutSolution;

	Tprobleme probleme;

public:
	Tsolution();
	Tsolution(Tprobleme);
	void prendreValeurs(Tsolution&);
	void evaluer();
	void rechercheLocale();
	void afficherSolution();

	int * getPere();
	int * getES();
	int * getCheminCritique();
	int getCoutSolution();
	Tprobleme getProbleme();

	void setCheminCritique(int *);
	void setES(int *);
	void setPere(int *);
};

