#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

using Board =vector<vector<bool>>;

bool correct[2][8][8];

int getColorCount(Board &b, int y, int x){
    int cnt = INT_MAX;
    for (int k =0 ;k<2;k ++) {
        int sum =0;
        for (int i=0;i < 8; i++) {
            for (int j = 0 ;j <8;j++){
                if (correct[k][i][j] != b[y+i][x+j]) sum++;
            }
        }
        cnt = min(cnt, sum);
    }
    return cnt;

}

int main() {

    int N, M;
    cin >> N >> M;
    Board board(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char k;
            cin >> k;
            board[i][j] = k == 'W';
        }
    }

    for (int k = 0; k < 2; k++) {
        bool color = k == 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                correct[k][i][j] = color;
                color = !color;
            }
            color = !color;
        }
    }

    int min_val = INT_MAX;
    for (int i = 0; i + 7 < N; i++) {
        for (int j = 0; j + 7 < M; j++) {
            min_val = min(min_val, getColorCount(board, i, j));
        }
    }

    cout << min_val;

    return 0;
}