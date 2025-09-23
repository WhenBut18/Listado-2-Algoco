#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cantidad, aux;
    while (true){
        cin >> cantidad;
        if (cantidad == 0){
            break;
        }
        map <int,int> orden;
        vector<int> listaA, listaAux, listaB;
        for (int i = 0; i < cantidad; i++){
            cin >> aux;
            listaA.push_back(aux);
            listaAux.push_back(aux);
        }
        for (int i = 0; i < cantidad; i++){
            cin >> aux;
            listaB.push_back(aux);
        }
        sort(listaA.begin(), listaA.end());
        sort(listaB.begin(), listaB.end());
        for (int i = 0; i < cantidad; i++){
            orden[listaA[i]] = listaB[i];
        }
        for (int i = 0; i < cantidad; i++){
            cout << orden[listaAux[i]] << endl;
        }
        cout << endl;
    }
    return 0;
}
