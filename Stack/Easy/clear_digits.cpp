#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string clearDigits(string s) {
        string ans;
        for(char ch : s){
            if(ch >= '0' && ch <= '9' && ans.length() != 0) ans.pop_back();
            else if(ch >= 'a' && ch <= 'z') ans.push_back(ch);
        }

        return ans;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 100
            s consists only of lowercase English letters and digits.
            The input is generated such that it is possible to delete all digits.
    */

    string s = "av4mnw4bt5";
    cout << clearDigits(s) << endl;

    return 0;
}