#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
        int size = s.length();
        int end = 0;
        for(int i=size-1;i>=0;i--){
            if(s[i] != ' '){
                end = i;
                break;
            }
        }

        int length = 0;
        while(end >= 0){
            if(s[end--] != ' ') length++;
            else break;
        }

        return length;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 10^4
            s consists of only English letters and spaces ' '.
            There will be at least one word in s.
    */

    string line = "luffy is still joyboy";
    cout << lengthOfLastWord(line) << endl;

    return 0;
}