#include <iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Igrac {
public:
    string ime;
    vector<int>Karta;
    Igrac(string _ime);
};


int main()
{
    int N;
    vector<Igrac>igrac;
    cout << "Unesi broj igraca:";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string ime;
        cout << "Unesi ime" << i+1 << ".igraca:";
        cin >> ime;
        igrac.push_back(Igrac(ime));
    }

    
}
