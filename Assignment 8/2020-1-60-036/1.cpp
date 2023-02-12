#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
vector<int>V[100],rounded;
int color[MAX],d[MAX],f[MAX],prev[MAX];
int white=0,grey=1,black=2,inf=10000,c=0,s=-1,e;

void DFS(int u)
{
    int x;
    color[u] = grey;
    c++;
    d[u] = c;

    for(int j=0;j<V[u].size();j++)
    {
        x = V[u][j];
        if(color[x]==white)
        {
            prev[x] = u;
            DFS(x);
        }
        else if(color[x] == grey && x!=prev[u])
        {
            s = u;
            e = x;
        }
    }
    color[u] = black;
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
        color[i]=white;
        prev[i] = inf;
        d[i] = inf;
        f[i] = inf;
    }

    for(int i=1;i<=node;i++)
    {
        if(color[i]==white)
        {
            DFS(i);
        }
    }
    if(s!=-1)
    {
        cout<<"YES"<<endl;
        rounded.push_back(s);
        while(e<s)
        {
            rounded.push_back(prev[s]);
            s = prev[s];
        }
        sort(rounded.begin(),rounded.end());
        for(int i=0;i<rounded.size();i++)
        {
            cout<<rounded[i]<<" ";
        }
    }
    else
    {
        cout<<"No";
    }
}



