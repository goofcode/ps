#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using Board = vector<vector<bool>>;
int M, N;

bool inRange(int y, int x) {
    return 0 <= y && y < M && 0 <= x && x < N;
}

int bfs(Board &b, Board &visited, int y, int x){

    int dx[] = {1,0,-1, 0};
    int dy[] = {0,1,0, -1};

    int area = 0;

    queue<pair<int, int >> q;
    q.push(make_pair(y,x));
    visited[y][x] = true;

    while(!q.empty()){
        auto c = q.front();
        q.pop();
        area++;

        for (int i =0 ;i< 4;i++){
            int ny = c.first + dy[i], nx = c.second +dx[i];
            if (inRange(ny, nx) && !visited[ny][nx] && !b[ny][nx]){
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }

    return area;
}

int main() {
    int K;
    cin >> M >> N >> K;
    Board b(M, vector<bool>(N, false));
    for (int k = 0; k < K; k++) {
        int by, lx, ty, rx;
        cin >> lx >> by >> rx >> ty;
        for (int y = M - ty; y < M - by; y++) {
            for (int x = lx; x < rx; x++) {
                b[y][x] = true;
            }
        }
    }

    int cnt = 0;
    Board visited(M, vector<bool>(N, false));
    vector<int> areas;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && !b[i][j]) {
                cnt++;
                areas.push_back(bfs(b, visited, i,j));
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << cnt << endl;
    for (auto a : areas){
        cout << a << " ";
    }

    return 0;
}