#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int> p;

    for (int i =0 ;i <N ;i++){
        int k ;
        cin >>k;
        p.push_back(k);
    }

    sort(p.begin(), p.end());

    int sum = 0, total = 0;
    for (int i= 0;i <N;i++){
        sum += p[i];
        total += sum;
    }
    cout << total;
    return 0;
}