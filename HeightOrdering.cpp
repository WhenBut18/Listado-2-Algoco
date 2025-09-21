#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int casos, casoActual, alumnoActual, pasos, contador;
    cin >> casos;
    for (int i = 0; i < casos; i++){
        vector<int> alumnos;
        cin >> casoActual;
        pasos = 0;
        for (int j = 0; j < 20; j++){
            contador = 0;
            cin >> alumnoActual;
            if (alumnos.empty()){
                alumnos.push_back(alumnoActual);
                continue;
            }
            for(auto a : alumnos){
                if (alumnoActual < a){
                    break;
                }
                contador++;
            }
            if (alumnos.size() == contador){
                alumnos.push_back(alumnoActual);
            } else {
                pasos += alumnos.size()-contador;
                alumnos.insert(alumnos.begin() + contador, alumnoActual);
            }
        }
        cout << casoActual << " " << pasos << endl;
    }
    return 0;
}
