#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        unordered_map<int, int> hash;
        for(int i=0;i<size1;i++){
            hash[nums1[i]]++;
        }

        for(int i=0;i<size2;i++){
            if(hash[nums2[i]] >= 1){
                return nums2[i];
            }
        }

        return -1;

        // Time Complexity -> O(n + m)
        // Space Complexity -> O(n)
        // Technique used -> hashmap
    }

int main(){

    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {5,6,7,8,9};
    cout << getCommon(v1,v2);

    return 0;
}