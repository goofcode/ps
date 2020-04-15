#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001] = {0,};

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int min_val = arr[i - 1] + 1;
        if (i % 3 == 0) min_val = min(min_val, arr[i / 3] + 1) ;
        if (i % 2 == 0) min_val = min(min_val, arr[i / 2] + 1);
        arr[i] = min_val;
    }

    cout << arr[n];
    return 0;
}