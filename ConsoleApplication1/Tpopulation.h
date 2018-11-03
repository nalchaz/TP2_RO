#pragma once
#include "Tvecteur.h"
#include "Tprobleme.h"
#include "Tsolution.h"
#include <unordered_map>
#include <string> 
#include <ctime>
#define TAILLEPOP 20

class Tpopulation
{

private:
	int n;
	int m;
	Tprobleme probleme;

public:
	Tpopulation(char *);
	Tvecteur * getListe();
	void genererPopulation();
	void genererFils();

	void insertionTrie(Tvecteur, int, int, int);

	void ecraserElem(int);
	
	void afficherPopulation(ostream&);

	bool testerDouble(Tvecteur);


private:
	int coutListe[TAILLEPOP];
	Tvecteur liste[TAILLEPOP];
	std::unordered_map<std::string, int> tableHash;

};

