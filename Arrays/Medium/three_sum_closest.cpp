#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        int difference = INT_MAX;
        int ans = 0;

        for(int i=0;i<size;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = size-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int temp_diff = abs(target - sum);
                if(temp_diff < difference){
                    difference = temp_diff;
                    ans = nums[i] + nums[left] + nums[right];
                }

                if(sum > target) right--;
                else if(sum < target) left++;
                else{
                    left++;
                    right--;
                }
            }
        }
 
        return ans;

        //      Time Complexity -> O(n^2)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            3 <= nums.length <= 500
            -1000 <= nums[i] <= 1000
            -10^4 <= target <= 10^4
    */

    vector<int> nums = {0,0,0};
    cout << threeSumClosest(nums) << endl;

    return 0;
}