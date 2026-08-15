#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
        int size1 = word1.length();
        int size2 = word2.length();
        int ptr1 = 0;
        int ptr2 = 0;

        string ans;
        int pos = 0;
        while(ptr1 < size1 && ptr2 < size2){
            if(pos % 2 == 0) ans.push_back(word1[ptr1++]);
            else ans.push_back(word2[ptr2++]);
            pos++;
        }

        while(ptr1 < size1) ans.push_back(word1[ptr1++]);
        while(ptr2 < size2) ans.push_back(word2[ptr2++]);

        return ans;

        //      Time Complexity -> O(n + m)
        //      Space Complexity -> O(n + m)
}

int main(){

    /*
        Constraints:
            1 <= word1.length, word2.length <= 100
            word1 and word2 consist of lowercase English letters.
    */

    string word1 = "abcde";
    string word2 = "edfgt";
    cout << mergeAlternately(word1,word2) << endl;

    return 0;
}