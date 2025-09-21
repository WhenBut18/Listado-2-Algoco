#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int casos;
    string nombreActual;
    while (true) {
        cin >> casos;
        if (casos == 0) {
            break;
        }
        vector<string> orden;
        for (int i = 0; i < casos; i++) {
            cin >> nombreActual;
            int pos = 0;
            while (pos < (int)orden.size() && 
                   orden[pos].substr(0, 2) <= nombreActual.substr(0, 2)) {
                pos++;
            }
            if (pos == (int)orden.size()) {
                orden.push_back(nombreActual);
            } else {
                orden.insert(orden.begin() + pos, nombreActual);
            }
        }
        for (auto r : orden) {
            cout << r << endl;
        }
        cout << "\n";
    }
    return 0;
}