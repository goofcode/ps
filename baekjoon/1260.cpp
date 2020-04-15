#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
using Adj = vector<vector<int>>;

int N, M, V;

bool inRange(int i) {
    return 0 < i && i<= N;
}

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(Adj &adj) {
    vector<bool> visited(N+1, false);
    deque<int> q;
    q.push_back(V);

    while(!q.empty()){
        int n = q.front();
        q.pop_front();

        if (visited[n]) continue;

        visited[n] = true;
        cout << n << " ";
        for (auto iter= adj[n].rbegin(); iter != adj[n].rend(); iter++){
            q.push_front(*iter);
        }
    }
    cout << endl;
}

void bfs(Adj &adj) {
    vector<bool> visited(N+1, false);
    deque<int> q;
    q.push_back(V);
    visited[V] = true;

    while(!q.empty()){
        int n = q.front();
        q.pop_front();

        cout << n << " ";
        for (auto iter= adj[n].begin(); iter != adj[n].end(); iter++){
            if (visited[*iter]) continue;
            visited[*iter] = true;
            q.push_back(*iter);
        }
    }
    cout << endl;
}

int main() {
    cin >> N >> M >> V;
    Adj adj(N+1);
    for (int i = 0; i < M; i++) {
        int j, k;
        cin >> j >> k;
        adj[j].push_back(k);
        adj[k].push_back(j);
    }
    for (int i=1;i <=N;i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(adj);
    bfs(adj);

    return 0;
}