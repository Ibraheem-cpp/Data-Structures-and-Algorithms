#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int size1 = players.size();
        int size2 = trainers.size();
        int i=0, j=0;
        int matchings = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        while(i < size1 && j < size2){
            if(players[i] <= trainers[j]){
                matchings++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return matchings;

        //      Time Complexity -> O(n log n) + O(n log n) : due to sorting
        //      Space Complexity -> O(log n) + O(log n) : due to sorting

        //      Approach : Sorting and two pointer
}

int main(){

    vector<int> players = {2,4,6,7};
    vector<int> trainers = {3,4,5};
    cout << matchPlayersAndTrainers(players,trainers) << endl;

    return 0;
}