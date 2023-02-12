#include <bits/stdc++.h>
using namespace std;

int knapsack(int benefit[], int weight[], int N, int W) {
    int i,j;
    int temp[2][W+1];

    for(i=0; i<=N; i++) {
        for(j=0; j<=W; j++) {
            if(i==0 || j==0) {
                temp[i%2][j]=0;
            }
            else if(weight[i-1]<=j) {
                temp[i%2][j]=max(benefit[i-1]+temp[(i-1)%2][j-weight[i-1]],temp[(i-1)%2][j]);
            }
            else {
                temp[i%2][j]=temp[(i-1)%2][j];
            }
        }
    }
    return temp[N%2][W];
}


int main() {
    while(1) {
        int N,W,i;

        cin >> N;
        cin >> W;

        int benefit[N];
        int weight[N];

        for(i=0; i<N; i++) {
            cin >> benefit[i];
        }
        for(i=0; i<N; i++) {
            cin >> weight[i];
        }
        cout << knapsack(benefit, weight, N, W);
        cout << endl;
        cout << endl;
   }
    return 0;
}
