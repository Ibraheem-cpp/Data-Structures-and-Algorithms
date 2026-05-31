#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int seconds = 0;
        int size = timeSeries.size();
        for(int i=0;i<size-1;i++){
            int startTime = timeSeries[i];
            int endTime = timeSeries[i] + duration - 1;
            if(endTime >= timeSeries[i+1]){
                seconds += timeSeries[i+1] - timeSeries[i];
            }
            else{
                seconds += duration;
            }
        }
        seconds += duration;

        return seconds;
}

int main(){

    vector<int> timeSeries = {3,5,6,8,9};
    int duration = 3;
    int seconds = findPoisonedDuration(timeSeries,duration);
    cout << seconds << endl;

    return 0;
}