#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][3];

int main() {

    int N; cin >> N;
    vector<int> red, green, blue;
    for (int i =0 ;i <N;i++){
        int r,g,b; cin >> r >> g >> b;
        red.push_back(r);
        green.push_back(g);
        blue.push_back(b);
    }

    dp[0][0] = red[0];
    dp[0][1] = green[0];
    dp[0][2] = blue[0];
    for (int i =1;i<N;i ++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + red[i];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + green[i];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + blue[i];
    }
    cout << min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2]));

    return 0;
}