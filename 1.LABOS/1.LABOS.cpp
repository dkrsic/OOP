#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Lokacija {
public:
    string ime, prezime;
    double x, y;
    vector<string> predmeti;
};

class Pedalina {
public:
    string boja;
    int kapacitet;
};

int main() {
    vector<Lokacija> lokacija;
    vector<Pedalina> predmet;

    int N;
    cout << "Unesite broj lokacija (N): ";
    cin >> N;
    for (int i = 0; i < N; ++i) {
        Lokacija novaLokacija;
        cout << "Unesite odgovornu osobu i GPS koordinate za " << i + 1 << ". lokaciju:"<<endl;
        cin >> novaLokacija.ime >> novaLokacija.prezime;
        cin >> novaLokacija.x >> novaLokacija.y;
        lokacija.push_back(novaLokacija);
    }

    int M = 0;
    cout << "Unesite broj pedalina (M):";
    cin >> M;

    
    int brLokacije = 0;
    for (int j = 0; j < M; ++j) {
        Pedalina novaPedalina;
        cout << "Unesite redni broj lokacije kojoj pripada" << j + 1 << ". pedalina:";
        cin >> brLokacije;
        cout << "Unesite boju i kapacitet pedaline:";
        cin >> novaPedalina.boja >> novaPedalina.kapacitet;
        predmet.push_back(novaPedalina);
    }


    for (int h = 0; h < N; ++h) {
        cout << h + 1 << ". " << lokacija[h].x << " " << lokacija[h].y << " " << lokacija[h].ime << " " << lokacija[h].prezime << " - pedaline: ";
        if (h+1==brLokacije) {
            cout << predmet[h-1].boja << " " << predmet[h-1].kapacitet;
        }
        cout << endl;
    }

    return 0;
}
