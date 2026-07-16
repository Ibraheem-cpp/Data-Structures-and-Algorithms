#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int>& nums) {
        int size = nums.size();

        bool monotoneIncreasing = true;
        bool monotoneDecreasing = true;
        for(int i=0;i<size-1;i++){
            if(nums[i] > nums[i+1]) monotoneIncreasing = false;
            if(nums[i] < nums[i+1]) monotoneDecreasing = false;

        }
        
        if(monotoneIncreasing || monotoneDecreasing) return true;
        return false;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 10^5
            -10^5 <= nums[i] <= 10^5
    */

    vector<int> nums = {3,2,2,3};
    if(isMonotonic(nums)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}