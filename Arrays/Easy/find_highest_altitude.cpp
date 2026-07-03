#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int max_altitude = 0;
        for(int num : gain){
            altitude += num;
            if(altitude > max_altitude){
                max_altitude = altitude;
            }
        }

        return max_altitude;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> Prefix Sum
}

int main(){

    vector<int> altitudes = {3,0,5,-6,3,6};
    cout << largestAltitude(altitudes) << endl;

    return 0;
}