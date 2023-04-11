#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BankovniRacun {
private:
	string brojRacuna;
	string tipRacuna;
	string tipKlijenta;
public:
	void setBrojRacuna(string _brojRacuna);
	void setTipRacuna(string _tipRacuna);
	void setTipKlijenta(string _tipKlijenta);
};

void BankovniRacun::setBrojRacuna(string _brojRacuna) {
	if (_brojRacuna.rfind("0", 0) == 0 && _brojRacuna.size() == 8) {
		brojRacuna = _brojRacuna;
	}
	else {
		if (_brojRacuna.rfind("0", 0) != 0) {
			cout << "Ne pocinje s nulom" << endl;
		}
		else if (_brojRacuna.size() != 8) {
			cout << "Ima vise ili manje od 8 brojeva" << endl;
		}
		else {
			cout << "Neka druga greska" << endl;
		}
	}
}

void BankovniRacun::setTipKlijenta(string _tipKlijenta) {
	if (_tipKlijenta._Equal("Fizicka") || _tipKlijenta._Equal("Privatna")) {
		tipRacuna = _tipKlijenta;
	}
	else {
		cout << "Provjeriti da li je ispisano Fizicka ili Privatna osoba" << endl;
	}
}

void BankovniRacun::setTipRacuna(string _tipRacuna) {
	if (_tipRacuna._Equal("Tekuci") || _tipRacuna._Equal("Ziro") || _tipRacuna._Equal("Devizni")) {
		tipRacuna = _tipRacuna;
	}
	else {
		cout << "Provjerite jeste li upisali Tekuci, Ziro ili Devizni" << endl;
	}
}

int main()
{
	BankovniRacun b1;
	string a, b, c;
	cout << "Upisi broj racuna" << endl;
	cin >> a;
	cout << "Upisi tip klijenta" << endl;
	cin >> b;
	cout << "Upisi tip racuna" << endl;
	cin >> c;
	b1.setBrojRacuna(a);
	b1.setTipKlijenta(b);
	b1.setTipRacuna(c);
}
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Osoba {
private:
    string ime;
    string prezime;
    int godinaRodjenja;
public:
    void setIme(string _ime);
    void setPrezime(string _prezime);
    void setGodinaRodjenja(int _godinaRodjenja);
    int getGodinaRodjenja() const;
    string getIme() const;
    string getPrezime() const;

    Osoba(string _ime, string _prezime, int _godinaRodjenja) {
        ime = _ime;
        prezime = _prezime;
        godinaRodjenja = _godinaRodjenja;
    }

    Osoba() {}
};

void Osoba::setIme(string _ime) {
    for (int i = 1; i < _ime.length(); i++) {
        if (isupper(_ime[i])) {
            _ime[i] += 32;
        }
    }
    if (isupper(_ime[0])) {
        ime = _ime;
    }
    else {
        cout << "Zbog nekog razloga nije moguce upisati ime" << endl;
    }
}

void Osoba::setPrezime(string _prezime) {
    for (int i = 1; i < _prezime.length(); i++) {
        if (isupper(_prezime[i])) {
            _prezime[i] += 32;
        }
    }
    if (isupper(_prezime[0])) {
        prezime = _prezime;
    }
    else {
        cout << "Zbog nekog razloga nije moguce upisati prezime" << endl;
    }
}

void Osoba::setGodinaRodjenja(int _godinaRodjenja) {
    if (_godinaRodjenja < 1900) {
        cout << "Godina je manja od 1900, nemoguce upisati" << endl;
    }
    else {
        godinaRodjenja = _godinaRodjenja;
    }
}

int Osoba::getGodinaRodjenja() const {
    return godinaRodjenja;
}

string Osoba::getIme() const {
    return ime;
}

string Osoba::getPrezime() const {
    return prezime;
}

bool sortingFunction(Osoba a, Osoba b) {
    return a.getGodinaRodjenja() < b.getGodinaRodjenja();
}




int main()
{
    vector<Osoba> listaOsoba;
    Osoba person;

    for (int i = 0; i < 5; i++) {
        string ime, prezime;
        int godinaRodjenja;
        cout << "Upisite ime, prezime i godinu rodjenja osobe > ";
        cin >> ime >> prezime >> godinaRodjenja;
        person.setIme(ime);
        person.setPrezime(prezime);
        person.setGodinaRodjenja(godinaRodjenja);
        listaOsoba.push_back(person);
    }

    sort(listaOsoba.begin(), listaOsoba.end(), sortingFunction);

    for (int i = 0; i < listaOsoba.size(); i++) {
        cout << listaOsoba[i].getIme() << " " << listaOsoba[i].getPrezime() << " " << listaOsoba[i].getGodinaRodjenja() << endl;
    }
}
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
#include <iostream>
#include <string>

using namespace std;

namespace Kalendar {
    class Datum;
    string kao_string(const Datum&);

    class Datum {
    public:
        Datum(int d, int m, int g) {
            if (d >= 1 && d <= 31) {
                _dan = d;
            }
            else {
                cout << "greska";
            }

            _mjesec = m;
            _godina = g;
        }

        void postavi_dan(int d) {
            if (d >= 1 && d <= 31) {
                _dan = d;
            }
            else {
                cout << "greska";
            }
        }

        int dan() const { return _dan; }
        int mjesec() const { return _mjesec; }
        int godina() const { return _godina; }


        /*
        23.1.2020.
        20200123

        x.vece_od(y);
        */
        bool vece_od(const Datum& d) {
            string a = kao_string(d);
            string b = kao_string(*this);

            return b > a;
        }

    private:
        int _dan;
        int _mjesec;
        int _godina;
    };

    string kao_string(const Datum& d) {
        string sg = to_string(d.godina());
        string sm = to_string(d.mjesec());
        if (sm.size() == 1) sm = "0" + sm;
        string sd = to_string(d.dan());
        if (sd.size() == 1) sd = "0" + sd;

        return sg + sm + sd;
    }

    void ispis(const Datum& d) {
        cout << d.dan();
    }
}

void main() {
    using namespace Kalendar;

    Datum d1(23, 11, 2020);
    Datum d2(4, 8, 2015);

    if (d1.vece_od(d2)) {
        cout << "d1 > d2";
    }
    else {
        cout << "nije vece";
    }

    // d.dan = 23;
    // d._mjesec = 11;
    // d._godina = 2020;
}
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
/***************************************************************************************************************************************************************/
#include <string>
#include <iostream>

using namespace std;

class Student {
public:
	// "obicni" konstruktori
	Student() {
		jmbag = new char[10];
	}

	Student(const char* jmbag) {
		this->jmbag = new char[10];
		strcpy_s(this->jmbag, strlen(jmbag) + 1, jmbag);
	}

	// kopirni konstruktor
	Student(const Student& postojeci) {
		// Student x = y ILI Student x(y)

		cout << "*** Student::Student(const Student& desni)\n";
		jmbag = new char[10];
		strcpy_s(jmbag, strlen(postojeci.jmbag) + 1, postojeci.jmbag);
	}

	// destruktor
	~Student() {
		delete[] jmbag;
		jmbag = nullptr;
		cout << "destructor za " << this << endl;
	}

	// kopirni operator=
	Student& operator=(const Student& desni) {
		/*
		Student x("...");
		Student y("...");
		...
		x = y;  // x.operator=(y)
		x = x;
		*/

		if (this != &desni) {
			cout << "*** Student& Student::operator=(const Student& desni)\n";
			strcpy_s(jmbag, strlen(desni.jmbag) + 1, desni.jmbag);
		}

		return *this;
	}

	// prijenosni konstruktor
	Student(Student&& privremeni) {
		cout << "*** Student::Student(Student&& privremeni) za " << privremeni.jmbag << endl;
		jmbag = privremeni.jmbag;

		/*
		Destruktor objekta 'student' ne smije obrisati ovaj niz znakova
		jer je taj niz alociran dinamicki i njegovu adresu ce koristiti
		pokazivac novog objekta. Stoga, da bi zastitili jmbag koji dijele
		oba objekta ovdje ga postavljamo na nullptr.
		*/
		privremeni.jmbag = nullptr;
	}

	// prijenosni operator=
	Student& operator=(Student&& privremeni) {
		if (this != &privremeni) {
			cout << "*** Student& Student::operator=(Student&& privremeni) za " << privremeni.jmbag << endl;
			delete[] jmbag;
			jmbag = privremeni.jmbag;

			/*
			Destruktor objekta 'student' ne smije obrisati ovaj niz znakova
			jer je taj niz alociran dinamicki i njegovu adresu ce koristiti
			pokazivac novog objekta. Stoga, da bi zastitili jmbag koji dijele
			oba objekta ovdje ga postavljamo na nullptr.
			*/
			privremeni.jmbag = nullptr;
		}

		return *this;
	}

	// ostale metode
	char* get_jmbag() const {
		return jmbag;
	}

	void set_jmbag(const char* noviJMBAG) {
		strcpy_s(jmbag, strlen(noviJMBAG) + 1, noviJMBAG);
	}

private:
	char* jmbag;
};


/*
Lokalni objekt (koji ce biti obrisan nakon return):
+-------+
|  ...	|
| jmbag	| --> dinamicki alociran niz znakova
|  ...	|
+-------+
*/
Student f() {
	/*
	s ce biti unisten nakon povratka iz f, pa se mora napraviti privremeni
	objekt kao povratna vrijednost.
	*/
	Student s("S1");
	cout << "adresa od s: " << &s << endl;
	return s;
}

void g(Student x) {
	cout << "funkcija g\n";
}

int main() {
	Student a1("A1");

	// isto sto i Student a2(a1)
	Student a2 = a1;	// kopirni konstruktor - NE pridruzivanje!

	a2.set_jmbag("I1");

	cout << "------------------------------\n";
	cout << "a1 JMBAG: " << a1.get_jmbag() << endl;
	cout << "a2 JMBAG: " << a2.get_jmbag() << endl;

	a1.set_jmbag("A2");

	cout << "a1 JMBAG: " << a1.get_jmbag() << endl;
	cout << "a2 JMBAG: " << a2.get_jmbag() << endl;

	Student a3;
	a3 = a1;

	cout << "------------------------------\n";
	cout << "a3 JMBAG: " << a3.get_jmbag() << endl;
	cout << "a1 JMBAG: " << a1.get_jmbag() << endl;

	a3.set_jmbag("M1");

	cout << "a3 JMBAG: " << a3.get_jmbag() << endl;
	cout << "a1 JMBAG: " << a1.get_jmbag() << endl;

	cout << "------------------------------\n";

	Student p;
	cout << ">>> poziv f()\n";
	p = f();
	cout << "p: " << p.get_jmbag() << endl;

	cout << "------------------------------\n";

	cout << ">>> poziv g()\n";
	g(p);  // kopiranje
	g(move(p));  // prijenos

	cout << "------------------------------\n";

	return 0;
}
