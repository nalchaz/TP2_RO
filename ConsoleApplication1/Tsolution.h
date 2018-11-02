#pragma once
#include "Tprobleme.h"
#include <iostream>

using namespace std;

class Tsolution
{
private:
	int ES[30 * 30];
	int PERE[30 * 30];
	int cheminCritique[30 * 30];

	Tprobleme probleme;

public:
	Tsolution(Tprobleme);
	int evaluer();
	void rechercheLocale();
	void afficherSolution();
	int * getPere();
	void setCheminCritique(int *, int);

};

