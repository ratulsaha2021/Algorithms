#include <bits/stdc++.h>
using namespace std;

int LIS(int num[], int N) {
    int i,j;
    vector<int>v;
    set<int>s;

    set<int>::iterator T;

    for (i=0; i<N; i++) {
        s.insert(num[i]);
    }

    for (T=s.begin(); T!=s.end(); T++) {
        v.push_back(*T);
    }
    int x = v.size();
    int dp[x+1][N+1];

    for (i=0; i<x+1; i++) {
        for (j=0; j<N+1; j++) {
            dp[i][j]=-1;
        }
    }

    for (i=0;i<x+1; i++) {
        for (j=0; j<N+1; j++) {
            if (i==0 || j==0) {
                dp[i][j]=0;
            }
            else if (num[j-1]==v[i-1]) {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[x][N];
}

int main() {
    while(1) {
        int N,i,x;
        cin >> N;
        int num[N];

        for(i=0; i<N; i++) {
            cin >> num[i];
        }

        x=LIS(num, N);
        cout << x;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    return 0;
}
