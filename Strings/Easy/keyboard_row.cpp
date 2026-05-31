#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> findWords(vector<string>& words) {
        vector<string> answer;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        unordered_map<char,int> hashmap;
        for(char ch : row1) hashmap[ch] = 1;
        for(char ch : row2) hashmap[ch] = 2;
        for(char ch : row3) hashmap[ch] = 3;

        int size = words.size();
        for(int i=0;i<size;i++){
            bool valid = true;
            int row = hashmap[tolower(words[i][0])];
            for(char ch : words[i]){
                if(hashmap[tolower(ch)] != row){
                    valid = false;
                    break;
                }
            }
            if(valid){
                answer.push_back(words[i]);
            }
        }
        
        return answer;

        //      Time Complexity -> O(n x m) : n -> total no. of words, m -> average lenght of each word
        //      Space Complexity -> O(26) -> O(1)
}

int main(){

    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    vector<string> answer = findWords(words);
    for(string st : answer){
        cout << st << " ";
    }

    return 0;
}