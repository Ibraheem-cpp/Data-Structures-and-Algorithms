#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkIfSortedAndRotated(vector<int>& nums) {
        int cliffs = 0;
        int size = nums.size();
        for(int i=0;i<size-1;i++){
            if(nums[i] > nums[i+1]){
                cliffs++;
            }
        }
        if(nums[size-1] > nums[0]){
            cliffs++;
        }

        if(cliffs > 1) return false;

        return true;
}

int main(){

    vector<int> v1 = {5,1,1,1,5};
    if(checkIfSortedAndRotated(v1)){
        cout << "True.\n";
    }
    else{
        cout << "False.\n";
    }
    

    return 0;
}