#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dominantIndex(vector<int>& nums) {
        int max = nums[0];
        int max_ind = 0;
        int size = nums.size();

        for(int i=1;i<size;i++){
            if(nums[i] > max){
                max = nums[i];
                max_ind = i;
            }
        }

        for(int i=0;i<size;i++){
            if(i == max_ind) continue;
            if(max < 2*nums[i]) return -1;
        }

        return max_ind;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            2 <= nums.length <= 50
            0 <= nums[i] <= 100
            The largest element in nums is unique.
    */

    vector<int> nums = {1,3,4,5,7,30};
    cout << dominantIndex(nums) << endl;

    return 0;
}