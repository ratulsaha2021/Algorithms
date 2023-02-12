#include <bits/stdc++.h>
using namespace std;

int factorial(int N) {
    int i;
    int fact=1;

    for(i=2; i<=N; i++) {
        fact = fact*i;
    }
    return fact;
}

int combination(int N, int R) {
    return factorial(N)/(factorial(R)*factorial(N-R));
}

int main() {
    int N,R;
    while (1) {
        cin >> N;
        cin >> R;

        int nCr = combination(N,R);

        cout << nCr;
        cout << endl;
        cout << endl;
    }
    return 0;
}
