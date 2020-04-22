#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T; cin >> T;
    unsigned long long dp[101] = {0, 1,1,1,2,2,3,4,5,7,9,12};
    for (int t =0; t< T;t++){
        int N; cin >> N;
        for (int i =12; i<=N;i++){
            dp[i] = dp[i-1] + dp[i-5];
        }
        cout << dp[N]<< endl;
    }
    return 0;
}