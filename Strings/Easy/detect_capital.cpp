#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word) {
    int size = word.length();
    int capitalCount = 0;

    for(int i=0;i<size;i++){
        if(word[i] >= 'A' && word[i] <= 'Z') capitalCount++;
    }

    if(capitalCount == 0) return true;
    if(capitalCount == size) return true;
    if(capitalCount == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;

    return false;

    //      Time Complexity -> O(n)
    //      Space Complexity -> O(1)
}

int main(){

    

    string word = "Leetcode";
    if(detectCapitalUse(word)){cout << "True.\n";}
    else {cout << "False.\n";}

    return 0;
}