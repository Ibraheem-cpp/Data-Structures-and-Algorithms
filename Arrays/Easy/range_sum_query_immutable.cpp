#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

 //     Time Complexity -> O(n) for prefix only once, O(1) for getting the sumRange
 //     Space Complexity -> O(n) for storing prefix sum

int main(){

    vector<int> nums = {3,6,4,6,2,6,2};
    NumArray num(nums);
    cout << num.sumRange(2,5) << endl;

    return 0;
}