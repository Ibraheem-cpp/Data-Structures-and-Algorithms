#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
        string ans;
        for(char ch : s){
            if(ans.empty()) ans.push_back(ch);
            else{
                if(ans.back() == ch) ans.pop_back();
                else ans.push_back(ch);
            }
        }

        return ans;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 10^5
            s consists of lowercase English letters.
    */

    string s = "alvavvlnjbkaln";
    cout << removeDuplicates(s) << endl;

    return 0;
}