#pragma once
#include "Tprobleme.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Tsolution
{
private:
	int ES[TAILLEVECMAX];
	int PERE[TAILLEVECMAX];
	int cheminCritique[TAILLEVECMAX];
	int coutSolution;

	Tprobleme probleme;

public:
	Tsolution();
	Tsolution(Tprobleme);
	void prendreValeurs(Tsolution&);
	void evaluer();
	Tvecteur rechercheLocale();
	void afficherSolution(ostream&);
	string toString();

	int * getPere();
	int * getES();
	int * getCheminCritique();
	int getCoutSolution();
	Tprobleme getProbleme();

	void setProbleme(Tprobleme);
	void setCheminCritique(int *);
	void setES(int *);
	void setPere(int *);
};

