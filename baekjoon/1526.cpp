#include <iostream>
#include <algorithm>

using namespace std;

bool checkGuemmin(int n) {

    while (n > 0) {
        int digit = n % 10;
        if(!(digit==4 || digit == 7))
            return false;
        n /= 10;
    }

    return true;
}

int main() {
    int n; cin >> n;
    for (int i =n; i >= 4; i--){
        if(checkGuemmin(i)) {
            cout << i;
            break;
        }
    }

    return 0;
}