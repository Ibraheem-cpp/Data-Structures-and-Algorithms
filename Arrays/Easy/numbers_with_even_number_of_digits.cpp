#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num : nums){
            int digits = 0;
            while(num > 0){
                num /= 10;
                digits++;
            }
            if(digits % 2 == 0) count++;
        }

        return count;

        //      Time Complexity -> O(n x d) : d -> no.of digits in largest number
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 500
            1 <= nums[i] <= 10^5
    */

    vector<int> nums = {242,6316,363};
    cout << findNumbers(nums) << endl; 

    return 0;
}