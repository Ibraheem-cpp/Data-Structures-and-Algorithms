#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        int size = nums.size();
        for(int i=0;i<k;i++){
            sum += nums[i];
        }

        double average = sum / k;

        int left = 0, right = k;
        while(right < size){
            sum += nums[right];
            sum -= nums[left];
            double newAvg = sum / k;
            if(newAvg > average) average = newAvg;
            right++;
            left++;
        }

        return average;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> Sliding Window
}

int main(){

    /*
        Constraints:
            n == nums.length
            1 <= k <= n <= 10^5
            -10^4 <= nums[i] <= 10^4
    */

    vector<int> nums = {5,1,6,2,-3,-5,-3,66,1};
    int k = 4;
    cout << findMaxAverage(nums, k) << endl;

    return 0;
}