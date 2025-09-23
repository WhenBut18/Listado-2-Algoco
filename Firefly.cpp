#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long largo, altura, aux, min = 0, cantmin = 0;
    bool trigger = false;
    cin >> largo >> altura;

    map<long long,long long> colisiones;
    for (long long i = 1; i <= altura+1; i++){
        colisiones[i] = 0;
    }

    while (largo--){
        cin >> aux;
        if (!trigger){
            colisiones[1] += 1;
            colisiones[aux+1] -= 1;
        } else {
            colisiones[altura-aux+1] += 1;
            colisiones[altura+1] -= 1;
        }
        trigger = !trigger;
    }

    long long acumulado = 0;
    for (long long i = 1; i <= altura; i++){
        acumulado += colisiones[i];
        if (min == 0){
            min = acumulado;
            cantmin = 1;
        } else {
            if (min > acumulado){
                min = acumulado;
                cantmin = 1;
            } else if (min == acumulado){
                cantmin += 1;
            }
        }
    }

    cout << min << " " << cantmin;
    return 0;
}
