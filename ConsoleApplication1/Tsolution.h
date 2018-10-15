#pragma once
#include "Tprobleme.h"
#include <iostream>

using namespace std;

class Tsolution
{
private:
	int ES[30 * 30];

	Tprobleme probleme;

public:
	Tsolution(Tprobleme);
	int evaluer();
	void afficherSolution();

};

