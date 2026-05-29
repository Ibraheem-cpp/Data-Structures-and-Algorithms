#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numberOfSpecialChars(string word) {
    int size = word.length();
    vector<int> lastLowerOccurence(26, -1);
    vector<int> firstUpperOccurence(26, -1);

    for(int i=0;i<size;i++){
        if(word[i] >= 'a' && word[i] <= 'z'){
            lastLowerOccurence[word[i] - 'a'] = i;
        }
    }
    
    for(int i=0;i<size;i++){
        if(word[i] >= 'A' && word[i] <= 'Z'){
            if(firstUpperOccurence[word[i] - 'A'] == -1){
                firstUpperOccurence[word[i] - 'A'] = i;
            }
        }
    }

    int count = 0;
    for(int i=0;i<26;i++){
        if(lastLowerOccurence[i] != -1 && lastLowerOccurence[i] < firstUpperOccurence[i]){count++;}
    }

    return count;

    //      Time Complexity -> O(n) + O(n) -> O(n)
    //      Space Complexity -> O(1) : because the vectors always have fixed size
    //          no matter the size of the input.
}

int main(){

    /*
        Constraints:
            1 <= word.length <= 2 * 10^5
            word consists of only lowercase and uppercase English letters.
    
    */

    string word = "AbBCab";
    cout << numberOfSpecialChars(word) << endl;

    return 0;
}