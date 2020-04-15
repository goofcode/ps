#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

bool checkLessPrior(deque<pair<int, int>> q, int priority) {
    for (auto &item : q) {
        if (item.second > priority) return true;
    }
    return false;
}

int main() {

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        deque<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            q.emplace_back(i, k);
        }

        int cnt = 0;
        while (true) {
            pair<int, int> current = q.front();
            q.pop_front();

            if (checkLessPrior(q, current.second)) {
                q.push_back(current);
            } else {
                cnt++;
                if (current.first == M) {
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}