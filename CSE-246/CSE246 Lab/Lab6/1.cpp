#include <bits/stdc++.h>
using namespace std;

void edge(vector<int> adj[], int s, int d) {
	adj[s].push_back(d);
	adj[d].push_back(s);
}


bool BFS(vector<int> adj[], int s, int d, int V, int temp[], int distance[]) {
	list<int> queue;
	bool visit[V];

	for (int i=0; i<V; i++) {
		visit[i] = false;
		distance[i] = INT_MAX;
		temp[i] = -1;
	}

	visit[s] = true;
	distance[s] = 0;
	queue.push_back(s);

	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visit[adj[u][i]] == false) {
				visit[adj[u][i]] = true;
				distance[adj[u][i]] = distance[u] + 1;
				temp[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				if (adj[u][i] == d)
					return true;
			}
		}
	}
	return false;
}

void shortestPath(vector<int> adj[], int s, int d, int V) {
	int temp[V], distance[V];

	if (BFS(adj, s, d, V, temp, distance) == false) {
		cout << "Not Connected";
		return;
	}

	vector<int> path;
	int temp2 = d;
	path.push_back(temp2);
	while (temp[temp2] != -1) {
		path.push_back(temp[temp2]);
		temp2 = temp[temp2];
	}

	cout << endl;
	cout << distance[d];
}


int main() {
	int V,E;
	int x,y;
	int s,d;

	cin >> V;
	cin >> E;
	V=V+1;

    vector<int> adj[V];

    for (int i=1; i<=E; i++) {
        cin >> x;
        cin >> y;
        edge(adj, x, y);
    }

    cin >> s;
    cin >> d;

    shortestPath(adj, s, d, V);
    return 0;
}

