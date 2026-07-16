#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        vector<int> hash(size+1, 0);

        for(int i=0;i<size;i++){
            hash[nums[i]]++;
        }

        vector<int> ans;
        for(int i=1;i<=size;i++){
            if(hash[i] == 2) {ans.push_back(i); break;}
        }
        for(int i=1;i<=size;i++){
            if(hash[i] == 0) {ans.push_back(i); break;}
        }

        return ans;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            2 <= nums.length <= 10^4
            1 <= nums[i] <= 10^4
    */

    vector<int> nums = {1,2,3,5,5};
    vector<int> ans = findErrorNums(nums);
    for(int num : ans) cout << num << " ";

    return 0;
}