#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
        int hash[26] = {0};
        int size = s.length();

        for(int i=0;i<size;i++){
            hash[s[i] - 'a']++;
        }

        for(int i=0;i<size;i++){
            if(hash[s[i] - 'a'] == 1){
                return i;
            }
        }

        return -1;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(26) -> O(1)
}

int main(){

    string s = "shfunfss";
    cout << firstUniqChar(s) << endl;

    return 0;
}