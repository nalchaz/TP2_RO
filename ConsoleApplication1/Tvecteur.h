#pragma once
#include <string>
#define TAILLEVECMAX 900

class Tvecteur
{
private:

	int V[TAILLEVECMAX];
	int tailleVecteur;

public:
	Tvecteur();
	void construireV(int, int);
	int trouveriEmeApparition(int, int);
	int * getVecteur();
	int getTailleVecteur();
	void setListe(int[TAILLEVECMAX]);
	void setTaille(int);
	std::string toString();
};

