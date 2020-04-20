#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Board = vector<vector<int>>;
using Visit = vector<vector<bool>>;

int N;

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int bfs(Board &b, Visit &v, int y, int x) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    v[y][x] = true;

    int cnt = 0;
    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int ny = c.first + dy[i], nx = c.second + dx[i];
            if (inRange(ny, nx) && !v[ny][nx] && b[ny][nx] == 1) {
                v[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }

    return cnt;

}

int main() {
    cin >> N;
    Board b(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char k;
            cin >> k;
            b[i][j] = k - '0';
        }
    }

    int cnt = 0;
    vector<int> nums;

    Visit visited(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (b[i][j] == 0 || visited[i][j]) continue;

            cnt++;
            nums.push_back(bfs(b, visited, i, j));
        }
    }

    sort(nums.begin(), nums.end());

    cout << cnt << endl;
    for (int n : nums){
        cout << n << endl;
    }

    return 0;
}