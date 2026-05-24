#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string generateRange(const vector<int>& nums, int start, int end){
    string range;
    if(start != end){
        range.append(to_string(nums[start]));
        range.append("->");
        range.append(to_string(nums[end]));
    }
    else{
        range.append(to_string(nums[start]));
    }

    return range;
}

vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        int start = 0, end = 0;
        int size = nums.size();

        if(size == 0) return ranges;

        for(int i=1;i<size;i++){
            if(nums[i] - 1 == nums[end]){
                end++;
            }
            else{
                string range = generateRange(nums, start, end);
                ranges.push_back(range);
                start = i;
                end = i;
            }
        }

        string range = generateRange(nums, start, end);
        ranges.push_back(range);

        return ranges;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1) -> the problem asks to return the vector, otherwise it's not needed
    }

int main(){

    vector<int> v1 = {1,3,5};
    vector<string> ranges = summaryRanges(v1);
    for(int i=0;i<ranges.size();i++){
        cout << ranges[i] << " ";
    }

    return 0;
}