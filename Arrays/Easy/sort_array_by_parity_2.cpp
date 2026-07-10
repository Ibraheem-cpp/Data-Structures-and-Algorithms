#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) {
        int size = nums.size();
        int even = 0;
        int odd = 1;
        
        while(even < size && odd < size){
            if(nums[even] % 2 != 0){
                if(nums[odd] % 2 == 0){
                    swap(nums[even], nums[odd]);
                    even += 2;
                    odd += 2;
                }
                else odd += 2;
            }
            else even += 2;
        }

        return nums;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> Two Pointers
        
}

int main(){

    /*
        Constraints:
            2 <= nums.length <= 2 * 10^4
            nums.length is even.
            Half of the integers in nums are even.
            0 <= nums[i] <= 1000
    */

    vector<int> nums = {2,4,5,7};
    sortArrayByParityII(nums);

    return 0;
}