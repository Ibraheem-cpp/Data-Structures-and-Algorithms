#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> hashset;
        int score = 0, maxScore = 0;
        int left = 0, right = 0;

        while(right < size){
            while(hashset.count(nums[right])){
                hashset.erase(nums[left]);
                score -= nums[left];
                left++;
            }
            hashset.insert(nums[right]);
            score += nums[right];
            maxScore = max(score, maxScore);
            right++;
        }

        return maxScore;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)

        //      Approach -> Sliding Window
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 10^5
            1 <= nums[i] <= 10^4
    */

    vector<int> nums = {4,6,2,7,4,2,5,7,8};
    cout << maximumUniqueSubarray(nums) << endl;

    return 0;
}