#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minElement(vector<int>& nums) {
        int min = INT_MAX;
        int size = nums.size();

        for(int i=0;i<size;i++){
            int digitSum = 0;
            int num = nums[i];
            while(num > 0){
                int digit = num % 10;
                digitSum += digit;
                num = num / 10;
            }
            nums[i] = digitSum;
            if(nums[i] < min){
                min = nums[i];
            }
        }

        return min;

        //      Time Complexity -> O(n * d) : d -> no. of digits
        //          since d is limited by constraints, it becomes constant so,
        //          Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= nums.length <= 100
            1 <= nums[i] <= 10^4
    */

    vector<int> vec = {12,43,56,76,31};
    int min = minElement(vec);
    cout << "Minimum Element : " << min << endl;

    return 0;
}