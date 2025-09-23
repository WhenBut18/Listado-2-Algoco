#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cantidad, altura;
    cin >> cantidad >> altura;

    vector<long long> diferencia(altura + 2, 0);
    bool trigger = true;

    for (int i = 0; i < cantidad; i++) {
        int aux;
        cin >> aux;
        if (trigger) {
            diferencia[1] += 1;
            if (aux + 1 <= altura) diferencia[aux + 1] -= 1;
        } else {
            diferencia[altura - aux + 1] += 1;
            diferencia[altura + 1] -= 1;
        }
        trigger = !trigger;
    }

    long long minObs = LLONG_MAX, count = 0, acum = 0;
    for (int i = 1; i <= altura; i++) {
        acum += diferencia[i];
        if (acum < minObs) {
            minObs = acum;
            count = 1;
        } else if (acum == minObs) {
            count++;
        }
    }

    cout << minObs << " " << count << "\n";
    return 0;
}
