#include<bits/stdc++.h>
using namespace std;

    int coinChange(int coins[],int n, int K)
    {

        int dp[n+1][K+1];

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=K;j++)
            {
                if(j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = 10000000;
                else if(coins[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
        if(dp[n][K]>10000000)
        {
           return -1;
        }
        else
        return dp[n][K];
    }
    int main()
    {
    int N,K;
    cin>>N;
    cin>>K;
    int coins[N];

    for(int i=0;i<N;i++)
    {
        cin>>coins[i];
    }
    int n = sizeof(coins)/sizeof(coins[0]);
    cout<<coinChange(coins,n,K);
    }


