#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Zaposlenik {
private:
    string ime;
    string prezime;
    int godStaz;
public:
    void setGodStaz(int _godStaz);
    int getGodStaz();
    Zaposlenik(string _ime, string _prezime) {
        ime = _ime;
        prezime = _prezime;
    }

    Zaposlenik(string _ime, string _prezime, int _godStaz) {
        ime = _ime;
        prezime = _prezime;
        if (_godStaz >= 0 && _godStaz <= 35) {
            godStaz = _godStaz;
        }
    }

    Zaposlenik() {}
};

int Zaposlenik::getGodStaz() {
    return godStaz;
}

void Zaposlenik::setGodStaz(int _godStaz) {
    if (_godStaz >= 0 && _godStaz <= 35) {
        godStaz = _godStaz;
    }
}

class Tvrtka {
private:
    string OIB;
    string adresa;
    string naziv;
public:
    vector<Zaposlenik*> popisZ;
    Tvrtka() {};
    ~Tvrtka() {
        for (int i = 0; i < popisZ.size(); i++) {
            delete popisZ[i];
        }
        cout << "Hej ja sam destruktor";
    };
    Tvrtka(const Tvrtka& t);
    Tvrtka& operator =(const Tvrtka& t);
    Tvrtka& operator =(Tvrtka&& t);
    Tvrtka(Tvrtka&& t);
    Tvrtka(const string _naziv, Zaposlenik& _z) {
        naziv = _naziv;
        popisZ.push_back(&_z);
    }


};

Tvrtka::Tvrtka(const Tvrtka& t) {
    for (int i = 0; i < t.popisZ.size(); i++) {
        popisZ.push_back(new Zaposlenik);
        *popisZ[i] = *t.popisZ[i];
    }
}

Tvrtka& Tvrtka::operator=(const Tvrtka& t) {
    if (this != &t) {
        for (int i = 0; i < popisZ.size(); i++) {
            delete popisZ[i];
        }
        popisZ.clear();
        for (int i = 0; i < t.popisZ.size(); i++) {
            popisZ.push_back(new Zaposlenik);
            *popisZ[i] = *t.popisZ[i];
        }
    }
    return *this;
}

Tvrtka& Tvrtka::operator =(Tvrtka&& t) {
    for (int i = 0; i < popisZ.size(); i++) {
        delete popisZ[i];
    }
    popisZ.clear();
    for (int i = 0; i < t.popisZ.size(); i++) {
        popisZ.push_back(t.popisZ[i]);
        t.popisZ[i] = NULL;
    }
    return *this;
}

Tvrtka::Tvrtka(Tvrtka&& t) {
    for (int i = 0; i < t.popisZ.size(); i++) {
        popisZ.push_back(t.popisZ[i]);
        t.popisZ[i] = NULL;
    }
}

int main()
{
    // B) dio
    //Test za godine staza
    Zaposlenik* Ante = new Zaposlenik("Ante", "Antic");
    Ante->setGodStaz(34);
    // zasto ne u konstruktoru postaviti godine -> u set metodi je provjera!
    // trebalo bi se izvesti

    Zaposlenik* Ivan = new Zaposlenik("Ivan", "Ivic");
    Ivan->setGodStaz(22);
    Zaposlenik* Jovan = new Zaposlenik("Jovan", "Jovic");
    Jovan->setGodStaz(24);
    // kod inicijalizacije ce doci do generiranja random godina staza, zato sto nismo ispunili sve clanske varijable
    // ne bude se izvelo

    //cout << Ante.getGodStaz() << endl;
    //cout << Ivan.getGodStaz() << endl;

    // C) dio
    // Kopirni konstruktor
    Tvrtka A("A", *Ante);
    Tvrtka B = A;
    for (int i = 0; i < B.popisZ.size(); i++) {
        cout << B.popisZ[i]->getGodStaz() << endl;
    }
    // Uspjesno su se iskopirali u drugu tvrtku (valjda)
    // Instanciranje + inicijalzacija lvalue objektom = KOPIRNI KONSTRUKTOR

    // D) dio
    // Operator pridruzivanja (kopiranje)
    Tvrtka C("Galekovic", *Jovan), D("Kaleb", *Ivan);
    D = C;
    for (int i = 0; i < D.popisZ.size(); i++) {
        cout << D.popisZ[i]->getGodStaz() << endl;
    }
    // Uspjesno su se iskopirali u drugu firmu
    // Inicijalizacija lvalue objektom = operator pridruzivanja (kopiranje)


    // E) dio
    Tvrtka E;
    E = Tvrtka("Belisce", *Ivan);
    // Uspjesno su se iskopirali u drugu firmu
    // Inicijalizacija rvalue objektom = operator pridruzivanja (prijenos)

    // F) dio
    Tvrtka F = move(Tvrtka());

}
/***********************************************************************************************************************************/
/***********************************************************************************************************************************/
/***********************************************************************************************************************************/
/***********************************************************************************************************************************/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Automobil
{
private:
    string proizvodac;
public:
    string gorivo;
    int cijena;
    void setPro(string _p)
    {
        _p.at(0) = toupper(_p.at(0));
        for (int i = 0; i < _p.size(); i++)
        {
            _p.at(i) = tolower(_p.at(i));
        }
        proizvodac = _p;
    }
    string getPro() const
    {
        return proizvodac;
    }
};

class AutoSalon
{
public:
    vector<Automobil*> polje;
    string naziv, adresa;
    AutoSalon() {}
    //KOPIRNI KONSTRUKTOR
    AutoSalon(const AutoSalon& tmp)
    {
        for (int i = 0; i < tmp.polje.size(); i++)
        {
            polje.push_back(new Automobil);
            polje[i] = tmp.polje[i];
        }
        naziv = tmp.naziv;
        adresa = tmp.adresa;
    }
    //OPERATOR PRIDRUZIVANJA SA DUBOKIM KOPIRANJEM
    AutoSalon& operator = (const AutoSalon& tmp)
    {
        if (this != &tmp)
        {
            for (int i = 0; i < polje.size(); i++)
            {
                delete polje[i];
            }
            polje.clear();
            for (int i = 0; i < tmp.polje.size(); i++)
            {
                polje.push_back(new Automobil);
                polje[i] = tmp.polje[i];
            }
            naziv = tmp.naziv;
            adresa = tmp.adresa;
        }
        return *this;
    }
    //OPERATOR PRIDRUZIVANJA SA SEMANTIKOM PRIJENOSA
    AutoSalon& operator = (AutoSalon&& tmp) noexcept
    {
        if (this != &tmp)
        {
            for (int i = 0; i < polje.size(); i++)
            {
                delete polje[i];
            }
            polje.clear();
            for (int i = 0; i < tmp.polje.size(); i++)
            {
                polje.push_back(tmp.polje[i]);
                tmp.polje[i] = NULL;
            }
            naziv = tmp.naziv;
            adresa = tmp.adresa;
        }
        return *this;
    }
    //DESTRUKTOR
    ~AutoSalon()
    {
        for (int i = 0; i < polje.size(); i++)
        {
            delete polje[i];
        }
        polje.clear();
    }
};

int main()
{
    AutoSalon A, C;
    AutoSalon B = A; //pozivanje kopirnog
    C = B; // operator pridruzivanja
    A = AutoSalon(); // operator pridruzivanja sa prijenosom
    return 0;
}