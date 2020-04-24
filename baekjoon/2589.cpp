#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
using Board = vector<vector<char>>;
using Visited = vector<vector<bool>>;

int N, M;
using Coord = struct {int y,x;};

bool inRange(int y, int x) {
    return  0 <= y && y < N && 0 <= x && x < M;
}

int bfs_max(Board &b, int y, int x) {

    int dx[] ={1,0,-1, 0};
    int dy[] = {0,1,0, -1};

    Visited v(N, vector<bool>(M));

    queue<pair<Coord, int>> q;
    q.push(make_pair(Coord{y,x}, 0));
    v[y][x] = true;

    int dist = 0;

    while(!q.empty()){
        auto c = q.front();
        q.pop();

        auto coord = c.first;
        dist = c.second;

        for (int i=0;i < 4; i++){
            int ny = coord.y + dy[i], nx = coord.x + dx[i];
            if (inRange(ny, nx) && !v[ny][nx] && b[ny][nx] == 'L'){
                q.push(make_pair(Coord{ny,nx}, dist+1));
                v[ny][nx] = true;
            }
        }
    }
    return dist;
}

int main() {
    cin >> N >> M;
    Board b(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            b[i][j] = c;
        }
    }

    int maximum = INT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (b[i][j] == 'W')
                continue;

            maximum = max(maximum, bfs_max(b, i, j));
        }
    }
    cout << maximum;
    return 0;
}