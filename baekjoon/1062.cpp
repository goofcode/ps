#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, K;
char defs[] = {'a', 'n', 'i','c', 't'};

bool check(string s, vector<bool> &selected) {
    for (char c : s) {
        if (!selected[c - 'a']) {
            return false;
        }
    }
    return true;
}

void dfs(vector<string> &words, vector<bool> &selected, char current, int count, int &maximum) {
    if (count == K) {
        int cnt = 0;
        for (auto s : words) {
            if (check(s, selected)) cnt++;
        }
        maximum = max(maximum, cnt);
        return;
    }

    if (current > 'z') {
        return;
    }

    dfs(words, selected, current + 1, count, maximum);

    if (!selected[current-'a']){
        selected[current - 'a'] = true;
        dfs(words, selected, current + 1, count + 1, maximum);
        selected[current - 'a'] = false;
    }

}

int main() {
    cin >> N >> K;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    if (K < 5) {
        cout << 0;
        return 0;
    }

    int maximum = INT_MIN;
    vector<bool> selected(26);

    for (char c : defs){
        selected[c-'a'] = true;
    }

    dfs(words, selected, 'b', 5, maximum);

    cout << maximum;

    return 0;
}