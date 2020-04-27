#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {

    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0; j<=i;j++){
            cin >> v[i][j];
        }
    }

    for (int i=n-1; i>0 ;i--){
        for (int j=0;j <i;j++){
            v[i-1][j] += max(v[i][j], v[i][j+1]);
        }
    }

    cout << v[0][0];

    return 0;
}