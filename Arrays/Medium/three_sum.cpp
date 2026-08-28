#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<size;i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = size-1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0) right--;
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    right--;
                    left++;
                    while(nums[left] == nums[left-1] && left < right) left++;
                }
            }
        }
 
        return ans;

        //      Time Complexity -> O(n^2) 
        //      Space Complexity -> O(log n) : sorting + O(n^2) : worst case for storing all triplets
}

int main(){

    /*
        Constraints:
            3 <= nums.length <= 3000
            -10^5 <= nums[i] <= 10^5
    */

    vector<int> nums = {1,5,-2,5,1,-6};
    vector<vector<int>> ans = threeSum(nums);

    return 0;
}