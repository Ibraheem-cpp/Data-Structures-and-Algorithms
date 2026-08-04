#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else{
                if(st.empty()) return false;
                if(ch == ')' && st.top() != '(') return false;
                else if(ch == '}' && st.top() != '{') return false;
                else if(ch == ']' && st.top() != '[') return false;
                st.pop();
            }
        }

        if(st.empty()) return true;
        return false;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 10^4
            s consists of parentheses only '()[]{}'.
    */

    string s = "({})[]";
    if(isValid(s)) cout << "Valid.\n";
    else cout << "Invalid.\n";

    return 0;
}