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
	int coutListe[TAILLEPOP];
	Tvecteur liste[TAILLEPOP];
	std::unordered_map<std::string, int> tableHash;

public:
	Tpopulation();
	Tpopulation(char *);
	Tpopulation(string);

	Tvecteur * getListe();
	int * getListeCout();
	void hashInsert(Tvecteur);
	void genererPopulation();
	Tsolution genererFils();
	void generationSuivante(); //Passe a la generation k+1

	void insertionTrie(Tvecteur&, int, int, int);
	void ecraserElem(int);
	
	void afficherPopulation(ostream&);

	string toString();

	bool testerDouble(Tvecteur);
	

};

