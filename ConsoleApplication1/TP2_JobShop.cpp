// TP2_JobShop.cpp : fichier projet principal.

#include "stdafx.h"
#include "Tprobleme.h"
#include "Tsolution.h"
#include "Tpopulation.h"
#include <iostream>
#include <ctime>

using namespace System;
using namespace std;


void testEvaluerEtRechercheLocale() {

	srand(time(NULL)); // initialisation de rand

	Tprobleme prob("ft06.txt");
	Tvecteur vect;
	//int vec[900] = { 5, 5, 4, 4, 5, 4, 0, 0, 4, 2, 5, 5, 1, 3, 1, 5, 0, 2, 2, 1, 1, 4, 2, 3, 2, 2, 1, 0, 4, 3, 3, 0, 3, 0, 1, 3 };
	prob.lireFichier();
	//prob.setVecteur(vec);
	prob.construireVecteur();
	prob.afficherProbleme();
	Tsolution uneSolution(prob);


	uneSolution.evaluer();
	std::cout << "APRES EVALUER :" << std::endl;

	uneSolution.afficherSolution(cout);

	std::cout << "\n\n\n*****************************************************************************************************\n\n" << std::endl;

	std::cout << "APRES RECHERCHE LOCALE :" << std::endl;

	uneSolution.rechercheLocale();
	uneSolution.afficherSolution(cout);

}

void testGenererPopulation() {

	srand(time(NULL)); // initialisation de rand

	Tpopulation population("ft06.txt");
	population.genererPopulation();
	population.afficherPopulation(cout);
}

void testGenererFils() {

	srand(time(NULL)); // initialisation de rand

	Tpopulation population("ft06.txt");
	population.genererPopulation();

	cout << "POPULATION AVANT L'ALGORITHME GENETIQUE\n" << endl;
	population.afficherPopulation(cout);

	for (int i = 0; i < 30; i++) {
		population.genererFils();
	}
	cout << "POPULATION APRES L'ALGORITHME GENETIQUE\n" << endl;
	population.afficherPopulation(cout);

	
}

int main() //args : array<System::String ^> ^args
{
	//testEvaluerEtRechercheLocale();
	//testGenererPopulation();
	testGenererFils();

	return 0;
}