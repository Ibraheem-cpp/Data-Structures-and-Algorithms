#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t) {
        stack<int> st1;
        stack<int> st2;

        for(char ch : s){
            if(ch == '#'){
                if(!st1.empty()) st1.pop();
            }
            else st1.push(ch);
        }

        for(char ch : t){
            if(ch == '#'){
                if(!st2.empty()) st2.pop();
            }
            else st2.push(ch);
        }

        if(st1 == st2) return true;
        return false;

        //      Time Complexity -> O(n + m)
        //      Space Complexity -> O(n + m)
}

int main(){

    /*
        Constraints:
            1 <= s.length, t.length <= 200
            s and t only contain lowercase letters and '#' characters.
    */

    string s = "gafg#jki#yt";
    string t = "qwet#kigs#e";
    if(backspaceCompare(s,t)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}