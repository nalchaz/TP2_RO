#pragma once
#include "Tvecteur.h"
#include "Tprobleme.h"
#include "Tsolution.h"
#include <unordered_map>
#include <sstream>
#include <string> 
#include <ctime>
#define TAILLEPOP 50

class Tpopulation
{

private:
	int n;
	int m;
	Tprobleme probleme;

public:
	Tpopulation(char *);
	Tpopulation(string);

	Tvecteur * getListe();
	int * getListeCout();
	void genererPopulation();
	void genererFils();

	void insertionTrie(Tvecteur&, int, int, int);
	void ecraserElem(int);
	
	void afficherPopulation(ostream&);

	string toString();

	bool testerDouble(Tvecteur);


private:
	int coutListe[TAILLEPOP];
	Tvecteur liste[TAILLEPOP];
	std::unordered_map<std::string, int> tableHash;

};

