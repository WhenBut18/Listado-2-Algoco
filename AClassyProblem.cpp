#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int claseValor(const string &s){
    if(s == "upper") return 3;
    if(s == "middle") return 2;
    return 1;
}

int main(){
    int casos;
    cin >> casos;
    while(casos--){
        int cantidad;
        cin >> cantidad;
        cin.ignore();

        vector<pair<string, vector<int>>> personas;
        int maxLen = 0;

        for(int k=0; k<cantidad; k++){
            string linea;
            getline(cin, linea);

            int pos = linea.find(':');
            string nombre = linea.substr(0, pos);
            string claseStr = linea.substr(pos+2);
            claseStr = claseStr.substr(0, claseStr.size()-6);
            vector<string> partes;
            string token;
            stringstream ss(claseStr);
            while(getline(ss, token, '-')){
                partes.push_back(token);
            }
            vector<int> valores;
            for(int i=(int)partes.size()-1; i>=0; i--){ 
                valores.push_back(claseValor(partes[i]));
            }
            maxLen = max(maxLen, (int)valores.size());
            personas.push_back({nombre, valores});
        }
        for(auto &p : personas){
            while((int)p.second.size() < maxLen){
                p.second.push_back(2);
            }
        }
        sort(personas.begin(), personas.end(), [](auto &a, auto &b){
            if(a.second != b.second)
                return a.second > b.second;
            return a.first < b.first; 
        });
        for(auto p : personas){
            cout << p.first << "\n";
        }
        cout << string(30,'=') << "\n";
    }
    return 0;
}