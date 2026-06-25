#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string mapping;
        int size = words.size();
        for(string word : words){
            int weight = 0;
            for(char ch : word){
                weight += weights[ch - 'a'];
            }
            weight = weight % 26;
            char letter = 'z' - weight;
            mapping.push_back(letter);
        }

        return mapping;

        //      Time Complexity -> O(n x w) : w -> length of word
        //      Space Complexity -> O(1) 
}

int main(){

    /*
        Constraints:
            1 <= words.length <= 100
            1 <= words[i].length <= 10
            weights.length == 26
            1 <= weights[i] <= 100
            words[i] consists of lowercase English letters.
    */

    vector<string> words = {"dgebg", "qqqvrrb", "svqvrv"};
    vector<int> weights = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8};
    string mapping = mapWordWeights(words, weights);
    cout << mapping << endl;

    return 0;
}