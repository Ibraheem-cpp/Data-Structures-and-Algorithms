#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minLength(string s) {
        string ans;
        for(char ch : s){
            if(ans.length() == 0) ans.push_back(ch);
            else if(ch == 'B' && ans.back() == 'A') ans.pop_back();
            else if(ch == 'D' && ans.back() == 'C') ans.pop_back();
            else ans.push_back(ch);
        }

        return ans.length();

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 100
            s consists only of uppercase English letters.
    */

    string s = "ANVOABCABIKCDE";
    cout << minLength(s) << endl;

    return 0;
}