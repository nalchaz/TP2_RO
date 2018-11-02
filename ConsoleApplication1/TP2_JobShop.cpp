// TP2_JobShop.cpp : fichier projet principal.

#include "stdafx.h"
#include "Tprobleme.h"
#include "Tsolution.h"
#include "Tpopulation.h"
#include <iostream>


using namespace System;

int main() //args : array<System::String ^> ^args
{
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

	uneSolution.afficherSolution(); 
	
	std::cout << "\n\n\n*****************************************************************************************************\n\n" << std::endl;
	
	std::cout << "APRES RECHERCHE LOCALE :" << std::endl;

	uneSolution.rechercheLocale();
	uneSolution.afficherSolution();


    return 0;
}
