#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long memo[31][31] = {0,};

unsigned long long comb(int n, int k){
    if (n-k < k) k = n-k;
    if (k==0) return 1;

    if (memo[n][k] != 0) return memo[n][k];

    unsigned long long ret = comb(n-1,k-1) + comb(n-1,k);
    memo[n][k] = ret;
    return ret;
}

int main() {

    int T; cin >>T;
    for (int t=0; t<T;t++){
        int n, m; cin >> n>> m;

        cout << comb(m,n)<<endl;
    }
    return 0;
}