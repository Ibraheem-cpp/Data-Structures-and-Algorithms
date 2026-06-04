#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;
        int current_time = 0;
        int landStartSize = landStartTime.size();
        int waterStartSize = waterStartTime.size();

        for(int i=0;i<landStartSize;i++){
            for(int j=0;j<waterStartSize;j++){
                current_time = landStartTime[i] + landDuration[i];
                if(current_time >= waterStartTime[j]){
                    current_time += waterDuration[j];
                }
                else{
                    current_time = waterStartTime[j] + waterDuration[j];
                }

                if(current_time < minTime){
                    minTime = current_time;
                }
            }
            
        }

        for(int i=0;i<waterStartSize;i++){
            for(int j=0;j<landStartSize;j++){
                current_time = waterStartTime[i] + waterDuration[i];
                if(current_time >= landStartTime[j]){
                    current_time += landDuration[j];
                }
                else{
                    current_time = landStartTime[j] + landDuration[j];
                }
                
                if(current_time < minTime){
                    minTime = current_time;
                }
            }
            if(current_time < minTime){
                minTime = current_time;
            }
        }

        return minTime;

        //      Time Complexity -> O(n x m) + O(n x m)
        //      Space Complexity -> O(1)

        //      Approach -> Brute Force : generate all possible outcomes 
}

int main(){

    /*
        Constraints:
            1 <= n, m <= 100
            landStartTime.length == landDuration.length == n
            waterStartTime.length == waterDuration.length == m
            1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 1000
    */

    vector<int> landStartTime = {2,4,6};
    vector<int> landDuration = {6,7,8};
    vector<int> waterStartTime = {12,14,56};
    vector<int> waterDuration = {12,22,13};
    cout << earliestFinishTime(landStartTime,landDuration,waterStartTime,waterDuration) << endl;


    return 0;
}