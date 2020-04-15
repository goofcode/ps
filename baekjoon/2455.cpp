#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector<int> in, out;
    for (int i = 0; i < 4; i++) {
        int j, k;
        cin >> j >> k;
        out.push_back(j);
        in.push_back(k);
    }

    int current = in[0];
    int max_val = in[0];
    for (int i = 1; i < 4; i++) {
        current = min(current + in[i] - out[i], 10000);
        max_val = max(current, max_val);
    }

    cout << max_val;

    return 0;
}