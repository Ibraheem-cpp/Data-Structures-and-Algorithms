#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_map<int,int> hashmap;
        stack<int> st;
        vector<int> answer(size1);

        for(int i=size2-1;i>=0;i--){
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            if(st.empty()) hashmap[nums2[i]] = -1;
            else hashmap[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        for(int i=0;i<size1;i++){
            answer[i] = hashmap[nums1[i]];
        }

        return answer;

        //      Time Complexity -> O(n + m)
        //      Space Complexity -> O(m)
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