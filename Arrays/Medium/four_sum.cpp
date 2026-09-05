#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<size;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1;j<size;j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = size - 1;
                while(left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target) right--;
                    else if(sum < target) left++;
                    else{
                        vector<int> vec = {nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(vec);

                        right--;
                        left++;
                        while(nums[right] == nums[right+1] && left < right) right--;
                    }
                }
            }
        }

        return ans;

        //      Time Complextiy -> O(n^3)
        //      Space Complexity -> O(n^3) : worst case for staring all quadruplets
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 200
            -10^9 <= nums[i] <= 10^9
-           10^9 <= target <= 10^9
    */

    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    vector<vector<int>> ans = fourSum(nums,target);

    return 0;
}