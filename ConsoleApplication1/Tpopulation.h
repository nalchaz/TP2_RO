#pragma once
#include "Tvecteur.h"
#include "Tprobleme.h"
#include "Tsolution.h"
#include <map>
#include <string> 


class Tpopulation
{

public:
	Tpopulation(char * nomFichier);
	Tvecteur * getListe();
	int coutListe[100];
	void genetique(int);


private:
	Tvecteur liste[100];
	std::map<std::string, int> tableHash;

};

