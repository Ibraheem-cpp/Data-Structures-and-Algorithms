#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int second_max = nums[1];
        int size = nums.size();

        for(int i=1;i<size;i++){
            if(nums[i] > maxi){
                second_max = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > second_max && nums[i] <= maxi) second_max = nums[i];
        }

        return (maxi-1)*(second_max-1);

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            2 <= nums.length <= 500
            1 <= nums[i] <= 10^3
    */

    vector<int> nums = {1,5,7,8,2,1};
    cout << maxProduct(nums) << endl;

    return 0;
}