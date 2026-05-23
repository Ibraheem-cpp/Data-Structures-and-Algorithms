#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int max_sum = 0;
        int size = nums.size();

        for(int i=1;i<size;i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
            }
            else{
                if(sum > max_sum){
                    max_sum = sum;
                }
                sum = nums[i];
            }
        }
        if(sum > max_sum){
            max_sum = sum;
        }

        return max_sum;
    }

int main(){

    vector<int> v1 = {1,2,1,1,5};
    cout << maxAscendingSum(v1);
    

    return 0;
}