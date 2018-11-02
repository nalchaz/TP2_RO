#pragma once

const int vmax = 30 * 30;

class Tvecteur
{
private:

	int V[vmax];

public:
	Tvecteur();
	void construireV(int, int);
	int trouveriEmeApparition(int, int);
	int * getVecteur();
	void setListe(int[vmax]);
};

