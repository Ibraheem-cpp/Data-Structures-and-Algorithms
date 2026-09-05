#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());

        int product1 = nums[size-1] * nums[size-2] * nums[size-3];
        int product2 = nums[0] * nums[1] * nums[size-1];

        return max(product1,product2);

        //      Time Complexity -> O(n log n)
        //      Space Complexity -> O(log n)
}

int main(){

    /*
        Constraints:
            3 <= nums.length <= 10^4
            -1000 <= nums[i] <= 1000
    */

    vector<int> nums = {4,2,1,5,-1};
    cout << maximumProduct(nums) << endl;

    return 0;
}