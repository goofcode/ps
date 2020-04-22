#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using Board = vector<vector<char>>;
using Visited = vector<vector<bool>>;

bool inRange(int y, int x) {
    return 0 <= y && y < 12 && 0 <= x && x < 6;
}

vector<pair<int, int>> bfs(Board &b, Visited &v, int y, int x) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    v[y][x] = true;

    char color = b[y][x];
    int cnt = 0;

    vector<pair<int, int>> points;

    while (!q.empty()) {
        auto c = q.front();
        q.pop();

        points.push_back(c);
        cnt++;

        for (int i = 0; i < 4; i++) {
            int ny = c.first + dy[i], nx = c.second + dx[i];
            if (inRange(ny, nx) && !v[ny][nx] && b[ny][nx] == color) {
                q.push(make_pair(ny, nx));
                v[ny][nx] = true;
            }
        }
    }
    return points;
}

void pushDown(Board &b) {
    for (int x = 0; x < 6; x++) {
        vector<char> line;
        for (int y = 0; y < 12; y++) {
            if (b[y][x] != '.') {
                line.push_back(b[y][x]);
                b[y][x] = '.';
            }
        }

        int y = 11;
        while (!line.empty()){
            char c = line.back();
            line.pop_back();
            b[y--][x] = c;
        }
    }
}

int main() {
    Board b(12, vector<char>(6));
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            char c;
            cin >> c;
            b[i][j] = c;
        }
    }

    int chain = 0;
    while (true) {
        Visited visited(12, vector<bool>(6, false));
        int exploded = 0;

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (b[i][j] == '.' || visited[i][j])
                    continue;

                auto points = bfs(b, visited, i, j);
                if (points.size() >= 4) {
                    exploded++;
                    for (auto p : points)
                        b[p.first][p.second] = '.';
                }
            }
        }

        if (exploded == 0)
            break;

        pushDown(b);
        chain++;
    }
    cout << chain;
    return 0;
}