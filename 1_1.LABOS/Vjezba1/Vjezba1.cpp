#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void usporedi(vector<int>niz) {
    int i = 0;
    int negativni;
    if (niz[i] < 0) {
        negativni = niz[i];
    }
    cout << "Negativni broj je:" << negativni;
}

void minmaks(vector<int>niz) {
    int max = *max_element(niz.begin(), niz.end());
    int min = *min_element(niz.begin(), niz.end());

    cout << "\nNajveci broj je:" << max;
    cout << "\nNajmanji broj je:" << min;

}

void obrni(string rijec) {
    reverse(rijec.begin(), rijec.end());
    cout << "Rijec obrnuto izgleda ovako:"<<rijec << endl;
}

int main()
{
    string rijec;
    cout << "Unesite rijec:";
    cin >> rijec;
    obrni(rijec);

    vector<int>niz;
    int n;
    int vrijednost;
    cout << "Unesite broj vrijednosti:";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << i+1 << "Vrijednost:";
        cin >>vrijednost;
        niz.push_back(vrijednost);
    }
    usporedi(niz);
    minmaks(niz);
 
}



/*obrnuti string
  ispisi negativne brojeve iz vektora
  najmanji i najveci broj u vektoru*/