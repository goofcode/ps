#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main () {

    int n; cin >> n;
    int dp[100001] = {0, 1, 2, 3, 1};

    for (int i =5; i<= n; i++){
        dp[i] = i;
        for (int k=1;k <= sqrt(i); k++){
            if (i-k*k >= 0){
                dp[i] = min(dp[i], dp[i-k*k] + 1);
            }
        }
    }
    cout << dp[n];

    return 0;
}