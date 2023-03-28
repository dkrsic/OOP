#include <iostream>
#include <string>
#include "Spil.h"
#include "Igrac.h"

int main(){
	// špil je izmiješan
	Spil Djelitelj(true); 
	vector<Igrac> igrac;
	int n;

	//kreiraj sve igrače
	cout << "Unesi broj igraca: ";
	cin >> n;
	if(n > 13){
		cout << "Broj igraca je prevelik!";
		return -1;
	}
	for(int i = 0; i < n; i++){
		string Ime;
		cout << "Unesi ime " << i+1 << ".igraca: ";
		cin >> Ime;
		igrac.push_back(Igrac(Ime));
	}

	// ispis svih karata u špilu
	cout << "\nKarte u spilu (" << Djelitelj.Karta.size() << "):\n";
	for(int i = 0; i < 52; i++)
		cout << Djelitelj.Karta[i] << "\t";
	cout << "\n\n";

	//podijeli karte svim igračima
	for(int i = 0; i < igrac.size(); i++){
		Djelitelj.PodijeliKarte(&igrac[i]);

		//ispis podijeljenjih karti 
		cout << igrac[i].Ime << " je dobio sljedece karte:\t";
		for(int j = 0; j < igrac[i].Karta.size(); j++)
			cout << igrac[i].Karta[j] << "\t";
		cout << endl;
	}
	cout << "\n\n";
	
	// ispis karata koji su ostali u špilu
	cout << "Preostale karte u spilu (" << Djelitelj.Karta.size() << "):\n";
	for(int i = 0; i < Djelitelj.Karta.size(); i++)
		cout << Djelitelj.Karta[i] << "\t";

	return 0;
}
