#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*Klasa Kompleksni koja obuhvaca realni i imaginarni dio kompleksnog broja*/
class Kompleksni {
public:
	double re, im;
};  
/*Funkcija za izracun modula kompleksnog broja*/
double Modul(Kompleksni Z) {
	return pow(Z.re * Z.re + Z.im * Z.im, 0.5);
}
/*Funkcija za usporedbu modula*/
bool KompleksniUsporedba(Kompleksni Z1, Kompleksni Z2) {
	return Modul(Z1) < Modul(Z2);
}
int main()
{
	int n;
	vector<Kompleksni>niz;

	cout << "Unesite N:";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		Kompleksni pom;
		cout << "niz[" << niz.size() << "].re = ";
		cin >> pom.re;
		cout << "niz[" << niz.size() << "].im = ";
		cin >> pom.im;
		niz.push_back(pom);
	}
	sort(niz.begin(), niz.end(), KompleksniUsporedba);
	for (int i = 0; i < n; i++)
		cout << "Z(" << niz[i].re << ((niz[i].im < 0) ? ("") : ("+")) << niz[i].im << ")\tModul: " << Modul(niz[i]) << endl;
	return 0;
}
