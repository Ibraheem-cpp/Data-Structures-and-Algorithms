#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for(int num : nums){
            hashmap[num]++;
            if(hashmap[num] > 1) return num;
        }

        return 0;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            2 <= n <= 5000
            nums.length == 2 * n
            0 <= nums[i] <= 10^4
            nums contains n + 1 unique elements and one of them is repeated exactly n times.
    */

    vector<int> nums = {1,2,3,3};
    cout << repeatedNTimes(nums) << endl;

    return 0;
}