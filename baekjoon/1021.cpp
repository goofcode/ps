#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int rotateCount(deque<int> & q, int t){
    int cnt =0;
    while (q[0] != t) {
        q.push_back(q.front());
        q.pop_front();
        cnt++;
    }
    return min(cnt, (int)(q.size()) - cnt);
}

int main () {
    int N, M;
    cin >> N >> M;
    deque<int> q;
    vector<int> target;

    for (int i=1; i<=N;i++)
        q.push_back(i);

    for (int i=0;i<M;i ++){
        int k ; cin >> k;
        target.push_back(k);
    }

    int total =0;
    for (auto t : target){
        total += rotateCount(q, t);
        q.pop_front();
    }

    cout<< total;

    return 0;
}