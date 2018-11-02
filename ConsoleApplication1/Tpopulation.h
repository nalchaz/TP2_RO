#pragma once
#include "Tvecteur.h"
#include "Tprobleme.h"
#include "Tsolution.h"
#include <functional>



class Tpopulation
{

public:
	Tpopulation();
	Tpopulation(char * nomFichier);
	Tvecteur * getListe();
	int coutListe[100];
	void genetique(int);


private:
	Tvecteur liste[100];
	std::hash<int> tableHash;

};

