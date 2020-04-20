#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printCase(vector<int> &nums, vector<int> build, int current){
    if(build.size() == 6){
        for (int i : build){
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    if (current >= nums.size())
        return;

    build.push_back(nums[current]);
    printCase(nums, build, current+1);

    build.pop_back();
    printCase(nums, build, current+1);
}

int main() {
    while (true){
        int k;
        cin >> k;

        if (k ==0 ) break;

        vector<int> nums;
        for(int i =0 ;i<k;i++){
            int j; cin >> j;
            nums.push_back(j);
        }
        printCase(nums, vector<int>(), 0);
        cout << endl;

    }


    return 0;
}