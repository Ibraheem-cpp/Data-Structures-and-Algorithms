#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string shortest = "";
        int hash[26] = {0};
        for(char ch : licensePlate){
            if(tolower(ch) >= 'a' && tolower(ch) <= 'z'){
                hash[tolower(ch) - 'a']++;
            }
        }

        for(string& word : words){
            int hash2[26] = {0};
            for(char ch : word){hash2[tolower(ch) - 'a']++;}

            bool matches = true;
            for(char ch : licensePlate){
                if(tolower(ch) >= 'a' && tolower(ch) <= 'z'){
                    if(hash[tolower(ch) - 'a'] > hash2[tolower(ch) - 'a']){
                        matches = false;
                        break;
                    }
                }
            }

            if(matches){
                if(word.size() < shortest.size() || shortest.size() == 0) shortest = word;
            }
        }

        return shortest;

        //      Time Complexity -> O(n x (l + m)) : l -> length of license plate, m -> length of longest word in words
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= licensePlate.length <= 7
            licensePlate contains digits, letters (uppercase or lowercase), or space ' '.
            1 <= words.length <= 1000
            1 <= words[i].length <= 15
            words[i] consists of lower case English letters.
    */

    string licensePlate = "1s3 PST";
    vector<string> words = {"steps", "step", "stripe"};
    cout << shortestCompletingWord(licensePlate, words) << endl;

    return 0;
}