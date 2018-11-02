#pragma once

const int vmax = 30 * 30;

class Tvecteur
{
private:

	int V[vmax];
	int tailleVecteur;

public:
	Tvecteur();
	void construireV(int, int);
	int trouveriEmeApparition(int, int);
	int * getVecteur();
	int getTailleVecteur();
	void setListe(int[vmax]);
};

