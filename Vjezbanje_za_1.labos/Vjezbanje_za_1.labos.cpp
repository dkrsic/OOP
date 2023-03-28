#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//
//class Student {
//public:
//    string Ime, JMBAG;
//    Student() {}
//    Student(string _Ime,string _JMBAG) {
//        Ime = _Ime;
//        JMBAG = _JMBAG;
//    }
//};
//
//class Bodovi {
//public:
//    Student student;
//    int bodovi;
//    Bodovi(Student _student, int _bodovi) {
//        student = _student;
//        bodovi = _bodovi;
//    }
//};
//
//class Kolegij {
//public:
//    string ime;
//    vector<Bodovi>bodovi;
//    Kolegij(string _ime, vector<Bodovi>_bodovi) {
//        ime = _ime;
//        bodovi = _bodovi;
//    }
//   
//};
//
//bool usporedi(Bodovi a,Bodovi b){
//    return a.bodovi < b.bodovi;
//}
//int main() {
//    vector<Bodovi> OOPBodovi{
//        Bodovi(Student("Ivana Ivic", "0246002475"), 25),
//        Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
//        Bodovi(Student("Marko Markic", "0246004234"), 32)
//    };
//    Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);
//    sort(OOP.bodovi.begin(), OOP.bodovi.end(), usporedi);
//    for (int i = 0; i < OOP.bodovi.size(); i++)
//        cout << OOP.bodovi[i].student.Ime << "\t"
//        << OOP.bodovi[i].student.JMBAG<< "\t"
//        << OOP.bodovi[i].bodovi << endl;
//
//    return 0;
//    }


//class Pedalina {
//public:
//	string boja;
//	int kapacitet;
//};
//
//class Lokacija {
//public:
//	string ime,prezime;
//	double x, y;
//	vector<string>pedaline;
//};
//
//int main() {
//	int N;
//	cout << "Unesite broj lokacija(N):";
//	cin >> N;
//	vector<Lokacija>nizLokacija;
//	for (int i = 0; i < N; ++i) {
//		Lokacija novaLokacija;
//		cout << "Unesite odgovornu osobu i GPS koordinate za " << i + 1 << ". lokaciju:"<<endl;
//		cin >> novaLokacija.ime>>novaLokacija.prezime;
//		cin >> novaLokacija.x >> novaLokacija.y;
//		nizLokacija.push_back(novaLokacija);
//	}
//	int M;
//	cout << "Unesite broj pedalina(M):";
//	cin >> M;
//	int brLokacije;
//	vector<Pedalina>pedala;
//	for (int i = 0; i < M; ++i) {
//		Pedalina novaPedalina;
//		cout << "Unesite redni broj lokacije kojoj pripada " << i + 1 << ". pedalina:";
//		cin >>brLokacije;
//		cout << "Unesite boju i kapacitet pedaline:";
//		cin >> novaPedalina.boja >> novaPedalina.kapacitet;
//		pedala.push_back(novaPedalina);
//	}
//	cout << "Ispis lokacija i pedalina:" << endl;
//	for (int i = 0; i < N; ++i) {
//		cout << i + 1 << "." << nizLokacija[i].x << " " << nizLokacija[i].y << " " << nizLokacija[i].ime <<" "<<nizLokacija[i].prezime<< " - pedaline:";
//		if (i + 1 == brLokacije) {
//			cout << pedala[i-1].boja << " " << pedala[i-1].kapacitet;
//		}
//		cout << endl;
//	}
//
//
//
//
//
//	return 0;
//}

//class BankovniRacun {
//private:
//	string brojRacuna;
//	string tipRacuna;
//	string tipKlijenta;
//public:
//	void setBrojRacuna(string _brojRacuna);
//	void setTipRacuna(string _tipRacuna);
//	void setTipKlijenta(string _tipKlijenta);
//};
//
//void BankovniRacun::setBrojRacuna(string _brojRacuna) {
//	if (_brojRacuna.rfind("0", 0) == 0 && _brojRacuna.size() == 8) {
//		brojRacuna = _brojRacuna;
//	}
//	else {
//		if (_brojRacuna.rfind("0", 0) != 0) {
//			cout << "Ne pocinje s nulom" << endl;
//		}
//		else if (_brojRacuna.size() != 8) {
//			cout << "Ima vise ili manje od 8 brojeva" << endl;
//		}
//		else {
//			cout << "Neka druga greska" << endl;
//		}
//	}
//}
//
//void BankovniRacun::setTipKlijenta(string _tipKlijenta) {
//	if (_tipKlijenta._Equal("Fizicka") || _tipKlijenta._Equal("Privatna")) {
//		tipRacuna = _tipKlijenta;
//	}
//	else {
//		cout << "Provjeriti da li je ispisano Fizicka ili Privatna osoba" << endl;
//	}
//}
//
//void BankovniRacun::setTipRacuna(string _tipRacuna) {
//	if (_tipRacuna._Equal("Tekuci") || _tipRacuna._Equal("Ziro") || _tipRacuna._Equal("Devizni")) {
//		tipRacuna = _tipRacuna;
//	}
//	else {
//		cout << "Provjerite jeste li upisali Tekuci, Ziro ili Devizni" << endl;
//	}
//}
//
//int main()
//{
//	BankovniRacun b1;
//	string a, b, c;
//	cout << "Upisi broj racuna" << endl;
//	cin >> a;
//	cout << "Upisi tip klijenta" << endl;
//	cin >> b;
//	cout << "Upisi tip racuna" << endl;
//	cin >> c;
//	b1.setBrojRacuna(a);
//	b1.setTipKlijenta(b);
//	b1.setTipRacuna(c);
//}


//class Osoba {
//private:
//    string ime;
//    string prezime;
//    int godinaRodjenja;
//public:
//    void setIme(string _ime);
//    void setPrezime(string _prezime);
//    void setGodinaRodjenja(int _godinaRodjenja);
//    int getGodinaRodjenja() const;
//    string getIme() const;
//    string getPrezime() const;
//
//    Osoba(string _ime, string _prezime, int _godinaRodjenja) {
//        ime = _ime;
//        prezime = _prezime;
//        godinaRodjenja = _godinaRodjenja;
//    }
//
//    Osoba() {}
//};
//
//void Osoba::setIme(string _ime) {
//    for (int i = 1; i < _ime.length(); i++) {
//        if (isupper(_ime[i])) {
//            _ime[i] += 32;
//        }
//    }
//    if (isupper(_ime[0])) {
//        ime = _ime;
//    }
//    else {
//        cout << "Zbog nekog razloga nije moguce upisati ime" << endl;
//    }
//}
//
//void Osoba::setPrezime(string _prezime) {
//    for (int i = 1; i < _prezime.length(); i++) {
//        if (isupper(_prezime[i])) {
//            _prezime[i] += 32;
//        }
//    }
//    if (isupper(_prezime[0])) {
//        prezime = _prezime;
//    }
//    else {
//        cout << "Zbog nekog razloga nije moguce upisati prezime" << endl;
//    }
//}
//
//void Osoba::setGodinaRodjenja(int _godinaRodjenja) {
//    if (_godinaRodjenja < 1900) {
//        cout << "Godina je manja od 1900, nemoguce upisati" << endl;
//    }
//    else {
//        godinaRodjenja = _godinaRodjenja;
//    }
//}
//
//int Osoba::getGodinaRodjenja() const {
//    return godinaRodjenja;
//}
//
//string Osoba::getIme() const {
//    return ime;
//}
//
//string Osoba::getPrezime() const {
//    return prezime;
//}
//
//bool sortingFunction(Osoba a, Osoba b) {
//    return a.getGodinaRodjenja() < b.getGodinaRodjenja();
//}
//
//
//
//
//int main()
//{
//    vector<Osoba> listaOsoba;
//    Osoba person;
//
//    for (int i = 0; i < 5; i++) {
//        string ime, prezime;
//        int godinaRodjenja;
//        cout << "Upisite ime, prezime i godinu rodjenja osobe > ";
//        cin >> ime >> prezime >> godinaRodjenja;
//        person.setIme(ime);
//        person.setPrezime(prezime);
//        person.setGodinaRodjenja(godinaRodjenja);
//        listaOsoba.push_back(person);
//    }
//
//    sort(listaOsoba.begin(), listaOsoba.end(), sortingFunction);
//
//    for (int i = 0; i < listaOsoba.size(); i++) {
//        cout << listaOsoba[i].getIme() << " " << listaOsoba[i].getPrezime() << " " << listaOsoba[i].getGodinaRodjenja() << endl;
//    }
//}