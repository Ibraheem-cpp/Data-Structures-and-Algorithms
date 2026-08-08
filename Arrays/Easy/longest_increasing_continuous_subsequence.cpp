#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
        int size = nums.size();
        int length = 1;
        int maxLength = 1;
        for(int i=0;i<size-1;i++){
            if(nums[i] < nums[i+1]){ 
                length++;
                maxLength = max(maxLength,length);
            }
            else length = 1;
        }

        return maxLength;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 10^4
            -10^9 <= nums[i] <= 10^9
    */

    vector<int> nums = {3,5,1,5,6,7,8,9};
    cout << findLengthOfLCIS(nums) << endl;

    return 0;
}