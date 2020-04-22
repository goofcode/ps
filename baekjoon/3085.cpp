#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;
int dx[] = {1, 0};
int dy[] = {0, 1};

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int find_max(vector<vector<char>> &b) {

    int maximum = INT_MIN;

    for (int y=0;y<N;y++){
        char current = b[y][0];
        int cnt = 1;
        for (int x=1; x<N;x++){
            if (b[y][x] != current){
                maximum = max(maximum, cnt);
                cnt = 1;
                current = b[y][x];
                continue;
            }
            cnt ++;
        }
        maximum = max(maximum, cnt);
    }

    for (int x=0;x<N;x++){
        char current = b[0][x];
        int cnt = 1;
        for (int y=1; y<N;y++){
            if (b[y][x] != current){
                maximum = max(maximum, cnt);
                cnt = 1;
                current = b[y][x];
                continue;
            }
            cnt ++;
        }
        maximum = max(maximum, cnt);
    }

    return maximum;
}

int main() {
    cin >> N;
    vector<vector<char>> b(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            b[i][j] = c;
        }
    }

    int maximum = INT_MIN;

    for (int i = 0; i < 2; i++) {
        for (int y1 = 0; y1 < N; y1++) {
            for (int x1 = 0; x1 < N; x1++) {
                int x2 = x1 + dx[i], y2 = y1 + dy[i];

                if (!inRange(y2, x2) || b[y1][x1] == b[y2][x2])
                    continue;

                swap(b[y1][x1], b[y2][x2]);
                maximum = max(maximum, find_max(b));
                swap(b[y1][x1], b[y2][x2]);
            }
        }
    }

    cout << maximum ;


    return 0;
}
