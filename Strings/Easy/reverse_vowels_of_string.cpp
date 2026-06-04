#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseVowels(string s) {
        int size = s.length();
        int start = 0, end = size - 1;
        while(start < end){
            if(tolower(s[start]) != 'a' && tolower(s[start]) != 'e' && tolower(s[start]) != 'i' && tolower(s[start]) != 'o' && tolower(s[start]) != 'u'){
                start++;
            }
            else{
                if(tolower(s[end]) != 'a' && tolower(s[end]) != 'e' && tolower(s[end]) != 'i' && tolower(s[end]) != 'o' && tolower(s[end]) != 'u'){end--;}
                else{
                    swap(s[start],s[end]);
                    start++;
                    end--;
                }
            }
        }

        return s;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> Two Pointer
}

int main(){

    string s = "blackKnight";
    reverseVowels(s);
    cout << s << endl;

    return 0;
}