#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string input, aux;
    getline(cin, input);
    istringstream ss(input);
    vector<string> filtros;
    while (ss >> aux){
        filtros.push_back(aux);
    }

    int cantCanciones, cantInstrucciones;
    vector<vector<string>> orden;

    cin >> cantCanciones;
    while (cantCanciones--){
        vector<string> cancion;
        for (int i = 0; i < (int)filtros.size(); i++){
            cin >> aux;
            cancion.push_back(aux);
        }
        orden.push_back(cancion);
    }

    cin >> cantInstrucciones;
    while (cantInstrucciones--){
        cin >> aux;
        auto it = find(filtros.begin(), filtros.end(), aux);
        int posicion = distance(filtros.begin(), it);
        int n = orden.size();

        for (int i = 1; i < n; i++) {
            vector<string> clave = orden[i];
            int j = i - 1;
            while (j >= 0 && orden[j][posicion] > clave[posicion]) {
                orden[j + 1] = orden[j];
                j--;
            }
            orden[j + 1] = clave;
        }

        for (int i = 0; i < (int)filtros.size(); i++){
            cout << filtros[i];
            if (i + 1 < (int)filtros.size()) cout << " ";
        }
        cout << "\n";

        for (auto &p : orden) {
            for (int i = 0; i < (int)p.size(); i++){
                cout << p[i];
                if (i + 1 < (int)p.size()) cout << " ";
            }
            cout << "\n";
        }
        cout << "\n"; 
    }
    return 0;
}
