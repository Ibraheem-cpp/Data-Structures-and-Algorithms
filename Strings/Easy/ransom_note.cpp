#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
        int ransomNoteHash[26] = {0};
        int magazineHash[26] = {0};
        int size1 = ransomNote.length();
        int size2 = magazine.length();

        for(int i=0;i<size1;i++){ransomNoteHash[ransomNote[i] - 'a']++;}
        for(int j=0;j<size2;j++){magazineHash[magazine[j] - 'a']++;}

        for(int i=0;i<size1;i++){
            if(magazineHash[ransomNote[i] - 'a'] < ransomNoteHash[ransomNote[i] - 'a']) return false;
        }

        return true;

        //      Time Complexity -> O(2n + m) -> O(n + m)
        //      Space Complexity -> O(26 + 26) -> O(1)
}

int main(){

    string magazine = "BlackKnight";
    string ransom = "lack";
    if(canConstruct(ransom, magazine)){
        cout << "Yes.\n";
    }
    else{
        cout << "No.\n";
    }

    return 0;
}