#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
        int size1 = s1.length();
        int size2 = s2.length();
        if(size1 > size2) return false;
        vector<int> h1(26,0);
        vector<int> h2(26,0);
        for(char ch : s1) h1[ch - 'a']++;
        for(int i=0;i<size1;i++) h2[s2[i] - 'a']++;

        if(h1 == h2) return true;

        for(int i=size1;i<size2;i++){
            h2[s2[i] - 'a']++;
            h2[s2[i-size1] - 'a']--;
            if(h1 == h2) return true;

        }
        return false;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> sliding window
}

int main(){

    /*
        Constraints:
            1 <= s1.length, s2.length <= 10^4
            s1 and s2 consist of lowercase English letters.
    */

    string s1 = "abx";
    string s2 = "abksienxbax";
    if(checkInclusion(s1,s2)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}