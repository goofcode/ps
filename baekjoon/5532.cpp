#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {

    int L, A,B,C,D;
    cin >> L >> A >> B >> C >> D;
    cout << min (L-ceil((double(A)/C)), L-ceil((double(B)/D)));
}