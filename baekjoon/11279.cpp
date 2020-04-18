#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> heap;
    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        if (k > 0) {
            heap.push_back(k);
            push_heap(heap.begin(), heap.end());
            continue;
        }

        if (heap.empty()) {
            printf("0\n");
            continue;
        }

        pop_heap(heap.begin(), heap.end());
        printf("%d\n", heap.back());
        heap.pop_back();
    }


    return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int main () {
//
//    int N; cin >> N;
//    priority_queue<int> pq;
//    for(int i=0 ;i<N;i++){
//        int k;
//        scanf("%d", &k);
//        if (k > 0) {
//            pq.push(k);
//            continue;
//        }
//
//        if (pq.empty()) {
//            printf("0\n");
//            continue;
//        }
//
//
//        printf("%d\n", pq.top());
//        pq.pop();
//    }
//
//
//    return 0;
//}