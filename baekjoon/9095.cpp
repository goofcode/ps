#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int cnt[15] = {1, 1,};
        for (int i = 2; i <= N; i++) {
            cnt[i] = cnt[i - 1];
            if (i - 2 >= 0) cnt[i] += cnt[i - 2];
            if (i - 3 >= 0) cnt[i] += cnt[i - 3];
        }
        cout << cnt[N] << endl;
    }

    return 0;
}