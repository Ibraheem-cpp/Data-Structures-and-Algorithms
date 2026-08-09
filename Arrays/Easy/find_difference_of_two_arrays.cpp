#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset1;
        unordered_set<int> hashset2;

        for(int num : nums1) hashset1.insert(num);
        for(int num : nums2) hashset2.insert(num);

        vector<vector<int>> ans;
        vector<int> vec;

        for(int num : hashset1){
            if(!hashset2.count(num)) vec.push_back(num);
        }
        ans.push_back(vec);

        vec.clear();

        for(int num : hashset2){
            if(!hashset1.count(num)) vec.push_back(num);
        }
        ans.push_back(vec);

        return ans;

        //      Time Complexity -> O(n + m)
        //      Space Complexity -> O(n + m)
}

int main(){

    /*
        Constraints:
            1 <= nums1.length, nums2.length <= 1000
            -1000 <= nums1[i], nums2[i] <= 1000
    */

    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {4,5,6,7,8};
    vector<vector<int>> ans = findDifference(nums1,nums2);

    return 0;
}