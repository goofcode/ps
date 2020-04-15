#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> getDigits(int n){
    vector<int> ret;
    while (n>0){
        ret.push_back(n%10);
        n/=10;
    }
    return ret;
}

bool checkHan(int n) {
    vector<int> digits = getDigits(n);
    if (digits.size() == 1) return true;

    int diff = digits[1] - digits[0];
    for (int i=1; i<digits.size()-1; i++){
        if (digits[i+1] - digits[i] != diff) return false;
    }

    return true;
}

int main(){
    int N;
    cin >> N;

    int count = 0;
    for (int i =1 ; i<=N; i++){
        if(checkHan(i)) count ++;
    }
    cout << count;
    return 0;
}