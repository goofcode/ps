#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * ... x x x 0 ...
 * ... x x 0 1 ...
 * ... x 0 1 1 ...
 */

int main() {
    int N;
    cin >> N;
    vector<int> wine;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        wine.push_back(k);
    }

    int dp[10001] = {
            wine[0],
            wine[0] + wine[1],
            max(wine[0] + wine[1], max(wine[0] + wine[2], wine[1] + wine[2]))
    };


    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + wine[i]);
        dp[i] = max(dp[i], dp[i - 3] + wine[i - 1] + wine[i]);
    }
    cout << dp[N - 1];

    return 0;
}