#include<bits/stdc++.h>
using namespace std;

int dp(int N, int W, int w[], int b[])
{
    int i,j;


    int knapsack[N+1][W+1];

    for(j=0;j<=W;j++)
        knapsack[0][j]=0;


    for(i=0;i<=N;i++)
        knapsack[i][0]=0;


    for(i=1;i<=N;i++)
    {
        for(j=1;j<=W;j++)
        {

            if(w[i-1]<=j)
            {
                knapsack[i][j]=max(knapsack[i-1][j],b[i-1]+knapsack[i-1][j-w[i-1]]);
            }

            else
            {
                knapsack[i][j]=knapsack[i-1][j];
            }
        }
    }


    return knapsack[N][W];

}

int main() {

        int N,W,i;

        cin >> N;
        cin >> W;

        int b[N];
        int w[N];

        for(i=0; i<N; i++) {
            cin >> b[i];
        }
        for(i=0; i<N; i++) {
            cin >> w[i];
        }
        cout <<dp(N, W,w,b);


    return 0;
}
