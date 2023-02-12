#include<bits/stdc++.h>
using namespace std;


int min_Coin(int coin[], int m, int K)
{

   if (K == 0) return 0;


   int res = INT_MAX;


   for (int i=0; i<m; i++)
   {
     if (coin[i] <= K)
     {
         int rem = min_Coin(coin, m, K-coin[i]);

         if (rem != INT_MAX && rem + 1 < res)
            res = rem + 1;
     }
   }
   return res;
}

int main()
{
    int N,K;
    cin>>N;
    cin>>K;
    int coin[N];
    for(int i=0;i<N;i++)
    {
        cin>>coin[i];
    }
    int m = sizeof(coin)/sizeof(coin[0]);
    cout<< min_Coin(coin, m, K);
    return 0;
}
