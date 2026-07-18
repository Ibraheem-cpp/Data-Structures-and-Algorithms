#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(const string& pattern : patterns){
            if(word.find(pattern) != string::npos) count++;
        }

        return count;

        // Time Complexity -> O(N x M x W) 
        //   N = number of strings in patterns
        //   M = max length of a pattern string
        //   W = length of the main word
        // Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= patterns.length <= 100
            1 <= patterns[i].length <= 100
            1 <= word.length <= 100
            patterns[i] and word consist of lowercase English letters.
    */

    vector<string> patterns = {"abc","ab", "bc","d"};
    string word = "abc";
    cout << numOfStrings(patterns,word) << endl;

    return 0;
}