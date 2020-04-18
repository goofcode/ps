#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, kim, lim;
    cin >> N >> kim >> lim;
    deque<int> d;
    for(int i =0;i<N;i++){
        d.push_back(i+1);
    }

    int cnt =1;
    while (d.size() > 1) {

        auto iter = d.begin();
        while (iter != d.end() && iter + 1 != d.end()){

            int left = *iter;
            int right = *(iter+1);

            if ((left == kim && right ==lim) || (left== lim && right == kim)){
                cout << cnt;
                return 0;
            }

            if (right != kim && right  != lim) {
                iter = d.erase(iter + 1);
            } else{
                iter = d.erase(iter);
                iter++;
            }
        }
        cnt++;
    }

    cout << -1;

    return 0;
}