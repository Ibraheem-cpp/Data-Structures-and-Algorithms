#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
        int size1 = haystack.length();
        int size2 = needle.length();
        if(size2 == 0) return 0;

        for(int i=0;i<size1;i++){
            if(haystack[i] == needle[0]){
                bool found = true;
                for(int j=0;j<size2;j++){
                    if(i + j >= size1 || haystack[i+j] != needle[j]){
                        found = false;
                        break;
                    }
                }
                if(found) return i;
            }
        }

        return -1;

        //      Time Complexity -> O(n x m)
        //      Space Complexity -> O(1)
}

int main(){

    string haystack = "blackknight";
    string needle = "lack";
    cout << strStr(haystack,needle) << endl;

    return 0;
}