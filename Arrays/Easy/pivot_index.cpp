#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        int leftSum = 0;
        int totalSum = 0;
        for(int num : nums) totalSum += num;
        
        for(int i=0;i<size;i++){
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum) return i;
            leftSum += nums[i];
        }

        return -1;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> Prefix Sum
}

int main(){

    /*
        Constraints
            1 <= nums.length <= 10^4
            -1000 <= nums[i] <= 1000
    */

    vector<int> nums = {3,4,5,6,7,8};
    cout << pivotIndex(nums) << endl;

    return 0;
}