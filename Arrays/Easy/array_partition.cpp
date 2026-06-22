#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int>& nums) {
        int maxSum = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0;i<size;i+=2){
            maxSum += nums[i];
        }

        return maxSum;

        //      Time Complexity -> O(n log n) + O(n)
        //      Space Complexity -> O(log n)
}

int main(){

    /*
        Constraints:
            1 <= n <= 10^4
            nums.length == 2 * n
            -10^4 <= nums[i] <= 10^4
    */

    vector<int> nums = {2,3,4,5,2,5,3};
    cout << arrayPairSum(nums) << endl;

    return 0;
}