#pragma once
#include "Tvecteur.h"
#include "Tprobleme.h"
#include "Tsolution.h"
#include <unordered_map>
#include <string> 
#define TAILLEPOP 100

class Tpopulation
{

public:
	Tpopulation();
	Tvecteur * getListe();
	void genererPopulation(char *);
	void genererFils();
	
	void afficherPopulation(ostream&);

	bool testerDouble(Tvecteur);


private:
	int coutListe[TAILLEPOP];
	Tvecteur liste[TAILLEPOP];
	std::unordered_map<std::string, int> tableHash;

};

