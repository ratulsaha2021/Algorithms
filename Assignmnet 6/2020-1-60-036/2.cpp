#include <bits/stdc++.h>
using namespace std;

int main()
{
        int M,N;
        cin >> M;
        cin >> N;
        int s[M][N];
        int i,j;

        for(i=0; i<M; i++)
            {
            for(j=0; j<N; j++)
            {
                cin >> s[i][j];
            }
        }

        int x,y,min;
        x=M+1;
        y=N+2;
        int m[x][y];

        for(i=0; i<x; i++)
            {
            for(j=0; j<1; j++)
            {
                m[i][j]=INT_MAX;
            }
        }

        for(i=0; i<1; i++)
            {
            for(j=1; j<y-1; j++)
            {
                m[i][j]=0;
            }
        }

        for(i=0; i<x; i++) {
            for(j=y-1; j<y; j++) {
                m[i][j]=INT_MAX;
            }
        }
        for(i=1; i<x; i++)
            {
            for(j=1; j<y-1; j++)
            {
                if(m[i-1][j-1] <= m[i-1][j] && m[i-1][j-1]<=m[i-1][j+1])
                {
                    min=m[i-1][j-1];
                }
                else if(m[i-1][j] <= m[i-1][j-1] && m[i-1][j]<=m[i-1][j+1])
                {
                    min=m[i-1][j];
                }
                else
                {
                    min=m[i-1][j+1];
                }
                m[i][j]=s[i-1][j-1]+min;
            }
        }

        int res = INT_MAX;

        for(i=x-1;i<x;i++)
            {
            for(j=1;j<y-1;j++)
            {
                if(res>m[i][j])
                {
                    res=m[i][j];
                }
            }
        }
        cout << res;
}
