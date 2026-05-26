#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numberOfSpecialChars(string word) {

        /*
            Approach 1 : uses two hash arrays to store count

        int size = word.length();
        int hash_small[26] = {0};
        int hash_large[26] = {0};

        for(int i=0;i<size;i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                hash_small[word[i] - 'a']++;
            }
            else if(word[i] >= 'A' && word[i] <= 'Z'){
                hash_large[word[i] - 'A']++;
            }
        }

        int count = 0;
        for(int i=0;i<size;i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                if(hash_small[word[i] - 'a'] > 0 && hash_large[word[i] - 'a'] > 0){
                    count++;
                    hash_small[word[i] - 'a'] = 0;
                    hash_large[word[i] - 'a'] = 0;
                }
            }
            else if(word[i] >= 'A' && word[i] <= 'Z'){
                if(hash_large[word[i] - 'A'] > 0 && hash_small[word[i] - 'A']){
                    count++;
                    hash_large[word[i] - 'A'] = 0;
                    hash_small[word[i] - 'A'] = 0;
                }
            }
        }
            
        */


        //      Approach 2 : uses a boolean array to store whether lowercase was seen or not

        int size = word.length();
        bool isLowerCaseSeen[26] = {false};

        for(int i=0;i<size;i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                isLowerCaseSeen[word[i] - 'a'] = true;
            }
        }

        int count = 0;

        for(int i=0;i<size;i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                if(isLowerCaseSeen[word[i] - 'A']){
                    count++;
                    isLowerCaseSeen[word[i] - 'A'] = false;
                }
            }
        }

        return count;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    string s = "ababAbbbcCB";
    cout << numberOfSpecialChars(s) << endl;

    return 0;
}