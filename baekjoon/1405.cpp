#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using Board = vector<vector<bool>>;

double p[4];    // e w s n
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

double dfs(Board &b, int y, int x, int move) {
    if (b[y][x]) {
        return 0;
    }
    if (move == 0) {
        return 1;
    }

    b[y][x] = true;
    double prob = 0;
    for (int i = 0; i < 4; i++) {
        prob += p[i] * dfs(b, y + dy[i], x + dx[i], move - 1);
    }
    b[y][x] = false;
    return prob;
}


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < 4; i++) {
        double d;
        cin >> d;
        p[i] = d / 100.0;
    }

    Board b(30, vector<bool>(30));
    int y = 15, x = 15;

    cout.precision(10);
    cout << dfs(b, y, x, N);

    return 0;
}