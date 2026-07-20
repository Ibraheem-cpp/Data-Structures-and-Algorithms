#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int size = s.length();
        int length = 0;
        unordered_set<char> hashset;
        int left = 0, right = 0;
        while(right < size){
            while(hashset.count(s[right])){
                hashset.erase(s[left]);
                left++;
            }
            hashset.insert(s[right]);
            right++;
            length = max(length, right-left);
        }

        return length;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1) : number of ASCII characters is constant

        //      Approach -> Sliding Window
}

int main(){

    /*
        Constraints:
            0 <= s.length <= 5 * 10^4
            s consists of English letters, digits, symbols and spaces.
    */

    string str = "fsnnngvwnb";
    cout << lengthOfLongestSubstring(str) << endl;

    return 0;
}