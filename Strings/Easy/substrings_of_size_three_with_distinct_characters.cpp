#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countGoodSubstrings(string s) {
        int size = s.length();
        int count = 0;
        for(int i=0;i<size-2;i++){
            if(s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) count++; 
        }

        return count;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)

        //      Approach -> Sliding Window
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 100
            s​​​​​​ consists of lowercase English letters.
    */

    string str = "xyzzaz";
    cout << countGoodSubstrings(str) << endl;

    return 0;
}