#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

using Board = vector<vector<int>>;

int N, M, K;

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void bfs(Board &b, int y, int x) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};


    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    b[y][x] = 2;

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        int cy = pos.first, cx = pos.second;
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i], nx = cx + dx[i];

            if (inRange(ny,nx) && b[ny][nx] == 1) {
                b[ny][nx] = 2;
                q.push(make_pair(ny, nx));
            }
        }
    }

}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        Board b(N, vector<int>(M, 0));
        for (int k = 0; k < K; k++) {
            int x, y;
            cin >> x >> y;
            b[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (b[i][j] == 1) {
                    cnt++;
                    bfs(b, i, j);
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}