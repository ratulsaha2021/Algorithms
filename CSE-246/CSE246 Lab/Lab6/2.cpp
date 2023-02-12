#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
    int V,E;
    cin >> V;
    cin >> E;

    vector<vector<int> > graph;
    vector<int> color;

    bool visit[1000];
    int x,y,i;

    graph.resize(E);
    color.resize(E , -1);
    memset(visit, 0, sizeof(visit));

    for(int i=0; i<E; i++) {
        graph[i].resize(E);
    }

    for(int i=0; i<E; i++) {
        cin >> x;
        cin >> y;
        x--;
        y--;
        graph[x][y]=1;
        graph[y][x]=1;
    }

    bool res;
    color[0]=1;
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int temp=q.front();
        q.pop();
        for (i=0; i<E; i++) {
            if (graph[temp][i] && color[i] == -1) {
                color[i]=1-color[temp];
                q.push(i);
                res=true;
            }
            else if (graph[temp][i] && color[i]==color[temp])
                res=false;
        }
    }

    if(res) {
        cout << endl;
        cout<<"YES";
    }

    else {
        cout << endl;
        cout<<"NO";
    }

    return 0;
}
