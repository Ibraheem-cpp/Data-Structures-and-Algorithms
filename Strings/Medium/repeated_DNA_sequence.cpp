#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
        int size = s.length();
        vector<string> answer;
        if(size < 10) return answer;

        int left = 0, right = 9;
        unordered_set<string> hashset;
        unordered_set<string> repeated;
        
        while(right < size){
            string window = s.substr(left,10);
            if(hashset.count(window) && !repeated.count(window)){
                answer.push_back(window);
                repeated.insert(window);
            }
            else{
                hashset.insert(window);
            }
            left++;
            right++;
        }

        return answer;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)

        //      Approach -> Sliding Window
}

int main(){

    /*
        Constraints:
            1 <= s.length <= 105
            s[i] is either 'A', 'C', 'G', or 'T'.
    */

    string s = "ACGTGCAACGTTGCA";
    vector<string> repeated = findRepeatedDnaSequences(s);

    return 0;
}