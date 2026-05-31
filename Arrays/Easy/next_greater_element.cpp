#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_map<int,int> hashmap;
        for(int i=0;i<size2;i++){
            hashmap[nums2[i]] = i;
        }

        vector<int> answer;
        for(int i=0;i<size1;i++){
            int ind = hashmap[nums1[i]];
            bool found = false;
            for(int j=ind+1;j<size2;j++){
                if(nums2[j] > nums1[i]){
                    answer.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }
            if(!found) answer.push_back(-1);
        }

        return answer;

        //      Time Complexity -> O(nums1 x nums2)
        //      Space Complexity -> O(nums2)
}

int main(){

    /*
        Constraints:
            1 <= nums1.length <= nums2.length <= 1000
            0 <= nums1[i], nums2[i] <= 10^4
            All integers in nums1 and nums2 are unique.
            All the integers of nums1 also appear in nums2.
 
    */

    vector<int> nums1 = {2,6};
    vector<int> nums2 = {2,4,5,6};
    vector<int> answer = nextGreaterElement(nums1, nums2);
    for(int n : answer){
        cout << n << " ";
    }

    return 0;
}