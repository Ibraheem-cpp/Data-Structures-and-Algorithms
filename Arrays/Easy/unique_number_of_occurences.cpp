#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
        int size = arr.size();
        unordered_map<int,int> hashMap;
        for(int i=0;i<size;i++){
            hashMap[arr[i]]++;
        }

        unordered_set<int> hashSet;
        for(auto& it : hashMap){
            if(hashSet.count(it.second)) return false;
            hashSet.insert(it.second);
        }

        return true;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            1 <= arr.length <= 1000
            -1000 <= arr[i] <= 1000
    */

    vector<int> nums = {4,5,6,1,3,2,5,1,3};
    if(uniqueOccurrences(nums)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}