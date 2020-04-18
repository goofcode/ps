#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> nums;
    nums.push_back(0);
    for (int i =0 ;i< N;i++){
        int k; cin >> k;
        nums.push_back(k);
    }

    int dp[1001] = {0, 1 };
    for (int i =2 ;i <= N ;i++){
        dp[i] = 1;
        for (int j =1;j<i; j++){
            if (nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    cout << *max_element(&dp[1], &dp[N+1]);

    return 0;
}