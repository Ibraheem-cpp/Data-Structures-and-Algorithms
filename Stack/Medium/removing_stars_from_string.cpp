#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeStars(string s) {
        string ans;
        for(char ch : s){
            if(ch == '*') ans.pop_back();
            else ans.push_back(ch);
        }

        return ans;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 10^5
            s consists of lowercase English letters and stars *.
            The operation above can be performed on s.
    */

    string s = "leet**co*de";
    cout << removeStars(s) << endl;

    return 0;
}