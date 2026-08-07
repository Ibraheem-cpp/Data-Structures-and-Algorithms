#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;

        for(char ch : s){
            if(ch == '(') depth++;
            else if(ch == ')'){
                if(depth > maxDepth) maxDepth = depth;
                depth--;
            }
        }

        return maxDepth;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 100
            s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
            It is guaranteed that parentheses expression s is a VPS.
    */

    string s = "(3+5)+((5*4)+2)";
    cout << maxDepth(s) << endl;

    return 0;
}