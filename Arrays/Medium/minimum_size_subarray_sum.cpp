#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int right = 0, left = 0;
        int sum = 0, len = 0, minLen = INT_MAX;
        
        while(right < size){
            sum += nums[right];
            while(sum >= target){
                len = right - left + 1;
                minLen = min(len, minLen);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        if(minLen == INT_MAX) return 0;

        return minLen;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> Sliding Window
    }

int main(){

    /*
        Constraints:
            1 <= target <= 10^9
            1 <= nums.length <= 10^5
            1 <= nums[i] <= 10^4
    */

    vector<int> nums = {4,6,6,2,6,3,6};
    int target = 4;
    cout << minSubArrayLen(target,nums) << endl;

    return 0;
}