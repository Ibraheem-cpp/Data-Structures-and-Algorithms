#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canAliceWin(vector<int>& nums) {
        int singleSum = 0;
        int doubleSum = 0;

        for(int num : nums){
            if(num < 10) singleSum += num;
            else doubleSum += num;
        }

        if(singleSum == doubleSum) return false;
        return true;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 100
            1 <= nums[i] <= 99
    */

    vector<int> nums = {4,5,12,54,61,1,8};
    if(canAliceWin(nums)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}