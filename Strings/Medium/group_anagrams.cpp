#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for(string& str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            hashmap[temp].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto& it : hashmap){
            ans.push_back(it.second);
        }

        return ans;

        //      Time Complexity -> O(n x (k + k log k + k)) + O(n x k) : n -> no.of total strings, k -> length of max string
        //              so, TC -> O(n x k log k)
        //      Space Complexity -> O(n x k)
}

int main(){

    /*
        Constraints:
            1 <= strs.length <= 10^4
            0 <= strs[i].length <= 100
            strs[i] consists of lowercase English letters.
    */

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    return 0;
}