#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix;
        for(int i=0;i<size;i++){
            if(i == 0) prefix.push_back(nums[i]);
            else prefix.push_back(nums[i] * prefix[i-1]);
        }
        vector<int> suffix(size);
        for(int i=size-1;i>=0;i--){
            if(i == size-1) suffix[i] = nums[i];
            else suffix[i] = nums[i] * suffix[i+1];
        }

        vector<int> ans;
        for(int i=0;i<size;i++){
            if(i == 0) ans.push_back(suffix[i+1]);
            else if(i == size-1) ans.push_back(prefix[i-1]);
            else ans.push_back(prefix[i-1] * suffix[i+1]);
        }

        return ans;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            2 <= nums.length <= 10^5
            -30 <= nums[i] <= 30
            The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
    */

    vector<int> nums = {2,5,6,3,7,4,3};
    vector<int> product = productExceptSelf(nums);

    return 0;
}