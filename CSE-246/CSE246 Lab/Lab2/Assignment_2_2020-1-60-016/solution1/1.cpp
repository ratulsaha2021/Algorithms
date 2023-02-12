#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int size,  int value) {
    int i, count=0;

    for(i = 0; i<size; i++) {
        while(value>=coins[i]) {
            value = value-coins[i];
            count++;
        }
        if(value==0)
            break;
    }
    return count;
}

int main() {
    int N,K,i;
    int input[N];
    int coins[N];

    while(1) {
        cin >> N;
        cin >> K;

        for(i=1; i<=N; i++) {
            cin >> input[i];
            coins[N-i]=input[i];
        }

        int minCount = minCoins(coins,N,K);
        cout << endl;
        cout << minCount;
        cout << endl;
        cout << endl;
    }
    return 0;
}

