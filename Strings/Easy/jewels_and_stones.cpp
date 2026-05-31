#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> hashset;
        for(char ch : jewels){
            hashset.insert(ch);
        }
        
        int count = 0;
        for(char ch : stones){
            if(hashset.count(ch)){
                count++;
            }
        }

        return count;

        //      Time Complexity -> O(j + s)
        //      Space Complexity -> O(j)
}

int main(){

    //      All characters of jewels are unique

    string jewels = "aAbc";
    string stones = "aaAAbBBCc";
    cout << numJewelsInStones(jewels,stones) << endl;

    return 0;
}