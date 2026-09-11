#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return true;
        int current = size-1;
        bool jump = false;

        for(int i=size-2;i>=0;i--){
            if(nums[i] + i >= current){
                jump = true;
                current = i;
            }
            else jump = false;
        }

        return jump;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 10^4
            0 <= nums[i] <= 10^5
    */

    vector<int> nums = {2,6,1,4,6,7};
    if(canJump(nums)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}