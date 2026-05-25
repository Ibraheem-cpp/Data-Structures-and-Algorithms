#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char isLower(char a){
    if(a >= 'A' && a <= 'Z'){return a+32;}
    return a;
}

bool isAnagram(string s, string t) {
        int size1 = s.length();
        int size2 = t.length();

        if(size1 != size2) return false;

        int hash[26] = {0};
        for(int i=0;i<size1;i++){
            hash[isLower(s[i]) - 97]++;
        }

        for(int j=0;j<size2;j++){
            hash[isLower(t[j]) - 97]--;
        }

        for(int i=0;i<26;i++){
            if(hash[i] > 0) return false;
        }

        return true;

        //      Time Complexity -> O(n) + O(n) + O(26) -> O(n)
        //          isLower(c) runs in constant time also -> O(1) 
        //      Space Complexity -> O(26) -> O(1), constant, it doesn't grow with input
}

int main(){

    string s = "rat";
    string t = "car";
    if(isAnagram(s,t)){
        cout << "Yes.\n";
    }
    else{
        cout << "No.\n";
    }

    return 0;
}