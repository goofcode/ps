#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    int time =0;
    while(true){
        int t; char a;
        cin>>t >> a;

        time += t;
        if (time > 210) {
            cout << k;
            break;
        }
        if (a == 'T'){
            k = k % 8 + 1;
        }
    }

    return 0;
}