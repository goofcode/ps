#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int bfs(vector<vector<int>> &trust, int s) {
    queue<int> q;
    vector<bool> visited(N, false);

    q.push(s);
    visited[s] = true;

    int cnt = 0;
    while (!q.empty()) {
        int c = q.front();
        q.pop();

        cnt++;
        for (int t : trust[c]) {
            if (!visited[t]) {
                visited[t] = true;
                q.push(t);
            }
        }
    }`
    return cnt;
}

int main() {

    cin >> N >> M;
    vector<vector<int>> trust(N);
    for (int i = 0; i < M; i++) {
        int k, l;
        cin >> k >> l;
        trust[l - 1].push_back(k - 1);
    }

    vector<int> best;
    int best_cnt = 0;
    for (int i = 0; i < N; i++) {
        int cnt = bfs(trust, i);
        if (cnt > best_cnt) {
            best.clear();
        }
        if (cnt >= best_cnt){
            best_cnt = cnt;
            best.push_back(i);
        }
    }

    sort(best.begin(), best.end());
    for (auto i : best) {
        cout << i + 1 << " ";
    }

    return 0;
}