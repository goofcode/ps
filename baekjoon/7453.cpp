#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n), D(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> AB(n * n), CD(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[n * i + j] = A[i] + B[j];
            CD[n * i + j] = C[i] + D[j];
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    unsigned long long total =0;
    int p1 = 0, p2 = n * n - 1;
    while (p1 < n * n && p2 >= 0) {
        if (AB[p1] + CD[p2] == 0) {
            int k=AB[p1], l=CD[p2];
            unsigned long long cnt1=0, cnt2=0;
            while(k==AB[p1] && p1 < n*n) {cnt1++; p1++;}
            while(l==CD[p2] && p2 >= 0) {cnt2++; p2--;}
            total += cnt1*cnt2;
        } else if (AB[p1] + CD[p2] < 0) {
            p1++;
        } else {
            p2--;
        }
    }

    cout << total;

    return 0;
}