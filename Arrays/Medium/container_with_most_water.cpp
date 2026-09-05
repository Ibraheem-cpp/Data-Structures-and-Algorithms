#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
        int size = height.size();
        int max_water = 0;

        int left = 0, right = size-1;
        while(left < right){
            int current_water = (right-left) * (min(height[left],height[right]));
            max_water = max(max_water,current_water);

            if(height[left] < height[right]) left++;
            else right--;
        }

        return max_water;

        //      Time Complexity -> O(n)
        //      Space Complextiy -> O(1)
}

int main(){

    /*
        Constraints:
            n == height.length
            2 <= n <= 10^5
            0 <= height[i] <= 10^4
    */

    vector<int> heights = {4,6,2,6,4,6,7};
    cout << maxArea(heights) << endl;

    return 0;
}