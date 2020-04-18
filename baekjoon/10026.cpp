#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using Board = vector<vector<char>>;
using Pos = struct {
    int y, x;
};

int N;

bool isSame(char c1, char c2, bool deficient) {
    if (!deficient)
        return c1 == c2;

    return c1 == c2 || (c1 == 'R' && c2 == 'G') || (c1 == 'G' && c2 == 'R');
}

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

void bfs(Board &b, vector<vector<bool>> &visited, int y, int x, bool deficient) {

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    queue<Pos> q;
    visited[y][x] = true;
    char color = b[y][x];
    q.push(Pos{y, x});

    while (!q.empty()) {
        Pos c = q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nx= c.x+dx[i], ny = c.y +dy[i];
            if (inRange(ny,nx) && !visited[ny][nx] && isSame(color, b[ny][nx], deficient)){
                visited[ny][nx] = true;
                q.push(Pos{ny, nx});
            }
        }
    }

}

int countArea(Board b, bool deficient) {

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                cnt++;
                bfs(b, visited, i, j, deficient);
            }
        }
    }

    return cnt;
}

int main() {
    cin >> N;
    Board b(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            b[i][j] = c;
        }
    }

    cout << countArea(b, false) << ' ' << countArea(b, true);

    return 0;
}