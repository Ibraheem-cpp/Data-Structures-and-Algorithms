#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int size = nums.size();
        vector<int> hash(size+1,0);

        for(int i=0;i<size;i++){
            hash[nums[i]]++;
        }

        vector<int> missing;

        for(int i=1;i<=size;i++){
            if(hash[i] == 0){
                missing.push_back(i);
            }
        }

        return missing;
}

int main(){

    /*
        Constraints:
            n == nums.length
            1 <= n <= 10^5
            1 <= nums[i] <= n
    */

    vector<int> nums = {2,3,5,6,7,8,3,2};
    vector<int> missing = findDisappearedNumbers(nums);
    for(int num : missing){
        cout << num << " ";
    }

    return 0;
}