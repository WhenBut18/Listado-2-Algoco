#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int casos, aux, max;
    cin >> casos;
    vector<int> numA;
    vector<int> numB;
    while(casos--){
        max = 0;
        cin >> aux;
        numA.push_back(aux);
        cin >> aux;
        numB.push_back(aux);
        sort(numA.begin(),numA.end());
        sort(numB.begin(),numB.end(), greater<int>());
        for (int i = 0; i < numA.size(); i++){
            if (max < (numA[i] + numB[i])){
                max = numA[i] + numB[i];
            }
        }
        cout << max << endl;
    }
    return 0;
}
