#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t) {
        char missing = 0;
        
        for(char ch : s){
            missing ^= ch;
        }
        for(char ch : t){
            missing ^= ch;
        }

        return missing;
}

int main(){

    string s = "aabbccddd";
    string t = "aabbccdd";
    cout << findTheDifference(s,t);

    return 0;
}