#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> numA, numB;

    for (int round = 0; round < N; round++) {
        int a, b;
        cin >> a >> b;
        numA.push_back(a);
        numB.push_back(b);

        vector<int> A = numA;
        vector<int> B = numB;

        sort(A.begin(), A.end());                
        sort(B.begin(), B.end(), greater<int>()); 

        int mx = 0;
        for (int i = 0; i < (int)A.size(); i++) {
            mx = max(mx, A[i] + B[i]);
        }
        cout << mx << "\n";
    }

    return 0;
}
