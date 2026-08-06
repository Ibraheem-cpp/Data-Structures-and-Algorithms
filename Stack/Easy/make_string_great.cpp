#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string makeGood(string s) {
        string ans;
        int size = s.length();

        for(int i=0;i<size;i++){
            if(ans.size() == 0) ans.push_back(s[i]);
            else if(s[i] >= 'a' && s[i] <= 'z' && ans.back() == s[i] - 32) ans.pop_back();
            else if(s[i] >= 'A' && s[i] <= 'Z' && ans.back() == s[i] + 32) ans.pop_back();
            else ans.push_back(s[i]);
        }

        return ans;

        //      Time Complexity -> O(n)
        //       Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 100
            s contains only lower and upper case English letters.
    */

    string s = "akcadNNASDGaavaA";
    cout << makeGood(s) << endl;

    return 0;
}