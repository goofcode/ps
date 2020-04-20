#include <iostream>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

int compare(deque<char> s1, deque<char> s2, int k){
    int diff =0 ;
    for (int i=0;i<s1.size() ;i++){
        if (s1[i] != s2[i+k]) diff++;
    }
    return diff;
}

int solve(deque<char> s1, deque<char> s2) {
    int min_diff = INT_MAX;
    for (int i=0; i+s1.size() <= s2.size(); i++){
        min_diff= min(min_diff, compare(s1,s2,i));
    }
    return min_diff;
}

int main() {
    string a,b;
    cin >> a >> b;
    deque<char> s1, s2;
    for (char c : a)
        s1.push_back(c);
    for (char c : b)
        s2.push_back(c);

    cout << solve(s1,s2);

    return 0;
}