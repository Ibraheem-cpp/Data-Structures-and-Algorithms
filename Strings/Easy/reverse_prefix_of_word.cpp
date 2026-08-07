#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch) {
        int ind = -1;
        int size = word.length();
        for(int i=0;i<size;i++){
            if(word[i] == ch){
                ind = i;
                break;
            }
        }

        if(ind != -1){
            int start = 0;
            while(start < ind){
                swap(word[start], word[ind]);
                start++;
                ind--;
            }
        }

        return word;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= word.length <= 250
            word consists of lowercase English letters.
            ch is a lowercase English letter.
    */

    string word = "adfgtbhdfgy";
    char ch = 't';
    cout << reversePrefix(word,ch) << endl;

    return 0;
}