#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        int length = 0, maxLength = 0;
        unordered_set<int> hashset;

        for(int num : nums) hashset.insert(num);

        for(int num : hashset){
            if(!hashset.count(num-1)){
                length = 0;
                int start = num;
                while(hashset.count(start)){
                    length++;
                    start++;
                }
                maxLength = max(length,maxLength);
            }
        }

        return maxLength;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            0 <= nums.length <= 10^5
            -10^9 <= nums[i] <= 10^9
    */

    vector<int> nums = {4,6,2,5,1,2,55,66,3,2};
    cout << longestConsecutive(nums) << endl;

    return 0;
}