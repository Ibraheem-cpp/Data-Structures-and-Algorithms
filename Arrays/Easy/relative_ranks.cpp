#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
        int size = score.size();
        map<int,int> hashmap;
        int rank = size;
        for(int i=0;i<size;i++){
            hashmap[score[i]] = i;
        }
        for(auto& it : hashmap){
            it.second = rank;
            rank--;
        }
        
        vector<string> position;
        for(int num : score){
            if(hashmap[num] == 1){position.push_back("Gold Medal");}
            else if(hashmap[num] == 2){position.push_back("Silver Medal");}
            else if(hashmap[num] == 3){position.push_back("Bronze Medal");}
            else{
                position.push_back(to_string(hashmap[num]));
            }
        }

        return position;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)

        //      Approach -> Hashmap
}

int main(){

    vector<int> scores = {10,3,8,9,4};
    vector<string> position = findRelativeRanks(scores);
    for(string str : position){
        cout << str << " ";
    }

    return 0;
}