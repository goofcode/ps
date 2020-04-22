#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
using Point = struct {
    int y, x;
};

bool movable(Point p1, Point p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) <= 1000;
}

bool isReachable(Point current, Point end, deque<Point> &mid) {
    if (movable(current, end)) return true;

    for (auto iter = mid.begin(); iter != mid.end(); iter++) {
        if (movable(current, *iter)){
            Point next = *iter;
            iter = mid.erase(iter);
            if(isReachable(next, end, mid))
                return true;
            mid.insert(iter, next);
        }
    }
    return false;
}

int main() {

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {

        int N;
        cin >> N;
        int x, y;

        cin >> y >> x;
        Point home{y, x};

        deque<Point> conv;
        for (int i = 0; i < N; i++) {
            cin >> y >> x;
            conv.push_back(Point{y, x});
        }

        cin >> y >> x;
        Point festival{y, x};

        cout << (isReachable(home, festival, conv) ? "happy" : "sad") << endl;
    }

    return 0;
}