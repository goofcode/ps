#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

//int main () {
//    int n; cin>> n;
//    vector<int> parents(n+1, -1);
//    int p1, p2; cin >> p1 >> p2;
//    int m ; cin >> m;
//    for (int i =0 ;i<m;i++){
//        int p, c; cin >> p >> c;
//        parents[c] = p;
//    }
//
//    // p1 acc
//    deque<int> p1_acc;
//    int current = p1;
//    p1_acc.push_front(current);
//    while(parents[current] != -1){
//        p1_acc.push_front(parents[current]);
//        current = parents[current];
//    }
//
//    // p2 acc
//    deque<int> p2_acc;
//    current = p2;
//    p2_acc.push_front(current);
//    while(parents[current] != -1){
//        p2_acc.push_front(parents[current]);
//        current = parents[current];
//    }
//
//    if ((p1_acc.empty() || p2_acc.empty()) || p1_acc[0] != p2_acc[0] ) {
//        cout << -1; return 0;
//    }
//
//    int i=0;
//    for (;i< min(p1_acc.size(), p2_acc.size()); i++) {
//        if (p1_acc[i] != p2_acc[i]) break;
//    }
//
//    cout << (p1_acc.size() - i) + (p2_acc.size() -i);
//
//    return 0;
//}

using Graph  = vector<vector<int>>;
int n;

int bfs(Graph &g, int src, int tgt){

    vector<bool> visited(n+1, false);
    queue<pair<int, int>> q;
    q.push(make_pair(src, 0));
    visited[src] =true;

    while(!q.empty()){
        auto c = q.front();
        q.pop();

        int current = c.first;
        int dist = c.second;

        if (current == tgt){
            return dist;
        }

        for (int f: g[current]){
            if (!visited[f]){
                visited[f] = true;
                q.push(make_pair(f, dist+1));
            }
        }
    }
    return -1;

}

int main() {

    cin >> n;

    int p1, p2;
    cin >> p1 >> p2;
    Graph g(n + 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, c;
        cin >> p >> c;
        g[p].push_back(c);
        g[c].push_back(p);
    }

    cout << bfs(g, p1, p2);

    return 0;
}