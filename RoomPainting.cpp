#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long cantLatas, reqLatas, aux, perdida = 0;
    cin >> cantLatas >> reqLatas;
    vector<long long> latas(cantLatas);
    for (long long i = 0; i < cantLatas; i++){
        cin >> latas[i];
    }
    sort(latas.begin(), latas.end());
    while (reqLatas--){
        cin >> aux;
        long long izq = 0, der = latas.size()-1;
        while (izq != der){
            if (latas[izq + ((der - izq)/2)] < aux){
                izq = (izq + ((der - izq)/2)) + 1;
            } else if (latas[izq + ((der - izq)/2)] > aux){
                der = izq + ((der - izq)/2);
            } else {
                break;
            } 
        }
        perdida += latas[izq + ((der - izq)/2)] - aux;
    }
    cout << perdida;
    
    return 0;
}
