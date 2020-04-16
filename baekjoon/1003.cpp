#include <iostream>
#include <algorithm>

using namespace std;

int main () {

    int T; cin  >> T;
    for (int t =0 ;t < T ; t++) {
        int N; cin >> N;
        int cnt0[50] = {1, 0};
        int cnt1[50] = {0, 1};

        for (int i=2; i<=N ;i++){
            cnt0[i] = cnt0[i-1] +cnt0[i-2];
            cnt1[i] = cnt1[i-1] +cnt1[i-2];
        }
        cout << cnt0[N] << " " << cnt1[N] << endl;
    }

    return 0;
}