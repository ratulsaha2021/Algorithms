#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> h;
int n,e;

int height(int curr, int p){
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        h[curr] = max(h[curr], height(it, curr));
    }
    h[curr] +=  1;
    return h[curr];
}

int diameter(int curr, int p){

    int mx1, mx2, mx_subtree;
    mx1 = mx2 = mx_subtree = INT_MIN;
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        if(mx1 < h[it]){
            mx2 = mx1;
            mx1 = h[it];
        } else {
            mx2 = h[it];
        }
    }
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        mx_subtree = max(mx_subtree, diameter(it, curr));
    }
    return max(mx_subtree, mx1 + mx2 + 1);
}

int main(){
    int u,v;
    cin >> n>>e;
    g.resize(n+1);
    h.resize(n+1, 0);
    for(int i=0; i<e ; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    height(1, -1);
    cout <<diameter(1, -1) -1 ;
    return 0;
}
