#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define INF (INT_MAX/2)

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> b(N, vector<int>(N, INF));

    for (int k = 0; k < M; k++) {
        int i,j; cin >> i >> j;
        b[i-1][j-1] = b[j-1][i-1] = 1;
    }

    for (int k = 0; k < N; k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                b[i][j] = min(b[i][j], b[i][k]+b[k][j]);
            }
        }
    }

    vector<int> dist(N, 0);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (i!=j) dist[i] += b[i][j];
        }
    }

    cout << distance(dist.begin(), min_element(dist.begin(), dist.end())) + 1;


    return 0;
}