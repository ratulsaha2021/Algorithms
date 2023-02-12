#include <bits/stdc++.h>
using namespace std;

void with_edge(vector<int> adj[], int source, int d)
{
    adj[source].push_back(d);
    adj[d].push_back(source);
}

bool BFS(vector<int> adj[], int source, int d, int v,
         int pred[], int dist[])
{

    list<int> queue;
    bool visited[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[source] = true;
    dist[source] = 0;
    queue.push_back(source);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                if (adj[u][i] == d)
                    return true;
            }
        }
    }

    return false;
}

void Distance(vector<int> adj[], int s,int d, int v)
{
    int pred[v], dist[v];

    if (BFS(adj, s, d, v, pred, dist) == false)
    {
        cout << "Given source and destination"<< " are not connected";
        return;
    }

    vector<int> path;
    int crawl = d;
    path.push_back(crawl);
    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    cout<< dist[d];
}
int main()
{
	int V,E;
	int x,y;
	int s,d;

	cin >> V;
	cin >> E;
	V=V+1;

    vector<int> adj[V];

    for (int i=1; i<=E; i++)
    {
        cin >> x;
        cin >> y;
        with_edge(adj, x, y);
    }

    cin >> s;
    cin >> d;

   Distance(adj, s, d, V);
    return 0;
}
