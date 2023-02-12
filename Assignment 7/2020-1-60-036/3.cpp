#include<bits/stdc++.h>
using namespace std;

int b=-(INT_MAX),d;
int vct[10001],dime[10001];
vector<int>graph[10001];
void bfs(int var,int d)
{
	vct[var]=1;
	dime[var]=d;
	if(dime[var]>b)
	{
		b=dime[var];
		d=var;
	}
	for(int des: graph[var])
	{
		if(vct[des]==0)
		{
			bfs(des,dime[var]+1);
		}
	}
}
int main()
{
	int V,E,x,y,i;
	cin>>V>>E;
	while(E--)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(1,0);
	b=-1;
	for(i=1;i<=V;i++)
    vct[i]=0;
	bfs(d,0);
	cout<<b<<endl;
	return 0;
}
