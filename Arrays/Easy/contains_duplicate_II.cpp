#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        int size = nums.size();

        for(int i=0;i<size;i++){
            if(hashmap.find(nums[i]) != hashmap.end()){
                if(i - hashmap[nums[i]] <= k){
                    return true;
                }
            }
            hashmap[nums[i]] = i;
        }

        return false;
}

int main(){

    vector<int> v1 = {1,2,1,1,5};
    if(containsNearbyDuplicate(v1, 3)){
        cout << "True.\n";
    }
    else{
        cout << "False.\n";
    }
    

    return 0;
}