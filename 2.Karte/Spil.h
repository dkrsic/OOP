#pragma once
#include <vector>
#include "Igrac.h"
using namespace std;

class Spil
{
public:
	vector<int> Karta;
	Spil(bool izmijesaj);
	void Podijeli4Karte(Igrac *X);
};

