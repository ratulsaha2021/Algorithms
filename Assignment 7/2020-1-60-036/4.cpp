#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
vector<int>V[100],rounded;
deque<int>Q;

int BFS(int node)
{
    int white,grey,black,inf,des;
    int color[MAX],d[MAX],prev[MAX],p[MAX];
    inf = 1000;
    white = 0;
    grey = 1;
    black = 2;

    int s,u,x;
    for(int i=1;i<=node;i++)
    {
        color[i] = white;
        prev[i] = inf;
        d[i] = inf;
        p[i] = 0;
    }
    cin>>s;
    color[s] = grey;
    d[s] = 0;
    p[s] = 1;
    prev[s] = NULL;
    Q.push_back(s);

    while(!Q.empty())
    {
        u = Q.front();
        rounded.push_back(u);
        Q.pop_front();
        for(int j=0;j<V[u].size();j++)
        {
            x = V[u][j];
            if(color[x]==white)
            {
                color[x] = grey;
                prev[x] = u;
                d[x] = d[u]+1;
                Q.push_back(x);
            }
            else if(color[x] == grey && d[x]==d[u]+1)
            {
                p[x] = p[x]+1;
                return 1;
            }

        }
        color[u] = black;
    }
}


int main()
{
    int node,edge,u,v,x;
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
    x = BFS(node);
    if(x==1)
    {
        printf("YES");

    }
    else
    {
        printf("NO");
    }
}


