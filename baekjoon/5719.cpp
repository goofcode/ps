#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

using Graph = vector<vector<int>>;
using Trace =vector<vector<int>>;
using Paths = vector<vector<int>>;
using pii = pair<int, int>;

int M, N;

int dijkstra(Graph &g, int s, int d, Trace &trace) {

    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> dist(N, INT_MAX);

    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        auto cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < N; i++) {

            if (g[cur][i] <0) continue;

            int new_dist = dist[cur] + g[cur][i];

            if (dist[i] > new_dist){
                trace[i].clear();
            }

            if (dist[i] >= new_dist){
                dist[i] = new_dist;
                pq.push(make_pair(dist[i], i));
                trace[i].push_back(cur);
            }
        }
    }
    return dist[d] == INT_MAX ? -1 : dist[d];
}

void deleteTrace(Graph &g, int d, Trace &t) {
    queue<int> q;
    vector<bool> visited(N, false);

    visited[d] = true;
    q.push(d);

    while(!q.empty()){
        int c = q.front();
        q.pop();

        for (int s : t[c]){
            g[s][c] = -1;
            visited[s] =true;
            q.push(s);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        int S, D;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        cin >> S >> D;
        Graph g(N, vector<int>(N, -1));
        for (int i = 0; i < M; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            g[u][v] = p;
        }

        Trace trace(N);
        dijkstra(g, S, D, trace);
        deleteTrace(g, D, trace);
        cout << dijkstra(g, S, D, trace) << endl;
    }

    return 0;
}