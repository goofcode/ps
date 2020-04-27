#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int box[101][101][101];

int M, N, H;

using Pos = struct {
    int h, n, m;
};

bool inRange(int h, int n, int m) {
    return 0 <= h && h < H && 0 <= n && n < N && 0 <= m && m < M;
}

int bfs() {
    int dm[] = {1, -1, 0, 0, 0, 0};
    int dn[] = {0, 0, 1, -1, 0, 0};
    int dh[] = {0, 0, 0, 0, 1, -1};

    queue<pair<Pos, int>> q;

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (box[h][n][m] == 1) {
                    q.push({{h, n, m}, 0});
                }
            }
        }
    }

    int time = 0;
    while (!q.empty()) {
        auto c = q.front();
        q.pop();

        Pos cp = c.first;
        time = c.second;

        for (int i = 0; i < 6; i++) {
            int nh = cp.h + dh[i], nn = cp.n + dn[i], nm = cp.m + dm[i];
            if (inRange(nh, nn, nm) && box[nh][nn][nm] == 0) {
                box[nh][nn][nm] = 1;
                q.push({{nh, nn, nm}, time + 1});
            }
        }

    }
    return time;
}

bool checkFinished() {
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (box[h][n][m] == 0) return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> M >> N >> H;

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> box[h][n][m];
            }
        }
    }

    int time = bfs();
    cout << (checkFinished() ? time : -1);
    return 0;
}