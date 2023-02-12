#include<bits/stdc++.h>
using namespace std;

int minCoinNum(int coinArray[], int N, int K) {
	int i,j,num;
	int valueArray[K+1];
	valueArray[0]=0;

	for (i=1; i<=K; i++) {
		valueArray[i]=INT_MAX;
	}

	for (i=1; i<=K; i++) {
		for (j=0; j<N; j++)
		if (coinArray[j]<=i) {
			num=valueArray[i-coinArray[j]];
			if (num!=INT_MAX && num+1<valueArray[i])
				valueArray[i]=num+1;
		}
	}

	if(valueArray[K]==INT_MAX) {
		return -1;
	}

	return valueArray[K];
}

int main() {
    int N,K,i;

    while(1) {
        cin >> N;
        cin >> K;

        int coinArray[N];

        for(i=0; i<N; i++) {
            cin >> coinArray[i];
        }

        cout << minCoinNum(coinArray, N, K);
        cout << endl;
        cout << endl;
    }
	return 0;
}

