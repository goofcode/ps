#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    int dp[10001] = {1, 0};
    for (int c: coins) {
        for (int i = 1; i <= k; i++) {
            if (i-c >= 0) {
                dp[i] += dp[i - c];
            }
        }
    }
    cout << dp[k];
    return 0;
}