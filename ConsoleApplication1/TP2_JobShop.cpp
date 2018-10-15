// TP2_JobShop.cpp : fichier projet principal.

#include "stdafx.h"
#include "Tprobleme.h"
#include "Tsolution.h"


using namespace System;

int main() //args : array<System::String ^> ^args
{
	int S;
	Tprobleme prob("ft06.txt");
	int vec[900] = { 5, 5, 4, 4, 5, 4, 0, 0, 4, 2, 5, 5, 1, 3, 1, 5, 0, 2, 2, 1, 1, 4, 2, 3, 2, 2, 1, 0, 4, 3, 3, 0, 3, 0, 1, 3 };
	prob.lireFichier();
	prob.setVecteur(vec);
	//prob.construireVecteur();
	prob.afficherProbleme();

	Tsolution uneSolution(prob);

	S = uneSolution.evaluer();
	uneSolution.afficherSolution();

	/*
	Tvecteur vecTest;
	int vec[900] = {0, 1, 1, 2, 2, 0, 1, 0, 2};

	Tprobleme probTest("test.txt");
	probTest.lireFichier();
	probTest.setVecteur(vec);
	probTest.afficherProbleme();
	Tsolution solProbTest(probTest);

	solProbTest.trouverSolution();
	solProbTest.afficherSolution();
	*/


    return 0;
}
