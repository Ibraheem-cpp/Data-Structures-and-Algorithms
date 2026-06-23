#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> leftRightDifference(vector<int>& nums) {
        int size = nums.size();
        vector<int> answer(size,0);
        int leftSum = nums[0];
        for(int i=1;i<size;i++){
            answer[i] = leftSum;
            leftSum += nums[i];
        }

        int rightSum = nums[size-1];
        for(int i=size-2;i>=0;i--){
            answer[i] = abs(answer[i] - rightSum);
            rightSum += nums[i];
        }

        return answer;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> Prefix Sum
}

int main(){

    vector<int> nums = {2,4,5,6,7,9};
    vector<int> difference = leftRightDifference(nums);
    for(int n : difference) cout << n << " ";

    return 0;
}