#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int cnt[101] = {0,};
    for (int i = 0; i < 3; i++) {
        int in, out;
        cin >> in >> out;
        for (int k=in;k<out;k++){
            cnt[k] ++;
        }
    }

    int  total = 0;
    for (int i : cnt){
        if (i == 1) total +=A;
        else if (i == 2) total += 2*B;
        else if (i == 3) total += 3*C;
    }

    cout << total;

    return 0;
}