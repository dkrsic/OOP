#include "Spil.h"
#include <algorithm>
#include <ctime>

Spil::Spil(bool izmijesaj):Karta(vector<int>(52)){
	for(int i = 0; i < 52; i++)
		Karta[i] = i + 1;
	if(izmijesaj){
		srand((unsigned)time(NULL));
		random_shuffle(Karta.begin(), Karta.end());
	}
}
void Spil::Podijeli4Karte(Igrac *X){
	/*for(int i = 0; i < 4; i++){
		X->Karta.push_back(Karta[0]);
		Karta.erase(Karta.begin());
	}  ili... */
	for(int i = 0; i < 4; i++)
		X->Karta.push_back(Karta[i]);
	for(int i = 0; i < 4; i++)
		Karta.erase(Karta.begin());
}


