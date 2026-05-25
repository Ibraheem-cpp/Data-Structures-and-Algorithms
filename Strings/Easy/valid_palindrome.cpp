#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char isLower(char a){
    if(a >= 'A' && a <= 'Z'){return a+32;}
    return a;
}

bool isPalindrome(string s) {
    int size = s.length();
    int start = 0, end = size-1;

    while(start < end){
        if(isalpha(s[start]) && isalpha(s[end])){
            if(isLower(s[start]) == isLower(s[end])){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        else if(isdigit(s[start]) && isdigit(s[end])){
            if(s[start] != s[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        else{
            if(!isalpha(s[start]) && !isdigit(s[start]) && !isalpha(s[end]) && !isdigit(s[end])){
                start++;
                end--;
            }
            else if(!isalpha(s[start]) && !isdigit(s[start])){
                start++;
            }
            else if(!isalpha(s[end]) && !isdigit(s[end])){
                end--;
            }
            else{
                return false;
            }

        }
    }

    return true;

    //      Time Complexity -> O(n) -> A single traversal through the string
    //      Space Complexity -> O(1) -> No extra space used
}

int main(){

    string s = "Was it a car or a cat I saw?";
    if(isPalindrome(s)){
        cout << "Yes.\n";
    }
    else{
        cout << "No.\n";
    }

    return 0;
}
