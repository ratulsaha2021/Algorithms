#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
vector<int>V[100],rounded;
int clor[MAX],d[MAX],f[MAX],prev[MAX];
int white=0,grey=1,black=2,inf=10000,mAx=-1,cl,c=0;
void DFS(int u)
{
    int x;
    clor[u] = grey;
    c++;
    d[u] = c;

    for(int j=0;j<V[u].size();j++)
    {
        x = V[u][j];
        if(clor[x]==white)
        {
            cl++;
            prev[x] = u;
            DFS(x);
        }
        if(cl>mAx)
        {
            mAx =cl;
        }
    }
    clor[u] = black;
    c++;
    f[u] = c;
}


int main()
{
    int node,edge,u,v,j;
    cin>>node>>edge;
    for(int i=1;i<=edge;i++)
    {
        cin>>u>>v;
        if(u==v)
        {
            V[u].push_back(v);
        }
        else
        {
            V[u].push_back(v);
            V[v].push_back(u);
        }
    }


    for(int i=1;i<=node;i++)
    {
        clor[i]=white;
        prev[i] = inf;
        d[i] = inf;
        f[i] = inf;
    }

    for(int i=1;i<=node;i++)
    {
        if(clor[i]==white)
        {
            cl=0;
            DFS(i);
        }
    }

    cout<<mAx+1;
}




