#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        while(start < end){
            if(nums[start] % 2 == 0) start++;
            else if(nums[end] % 2 != 0) end--;
            else swap(nums[start++], nums[end--]);
        }

        return nums;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 5000
            0 <= nums[i] <= 5000
    */

    vector<int> nums = {3,4,5,6,2,7,2,1};
    nums = sortArrayByParity(nums);

    return 0;
}