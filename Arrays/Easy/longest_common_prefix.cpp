#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0) return "";
        if(size == 1) return strs[0];

        int min_size = strs[0].size();
        for(int i=1;i<size;i++){
            if(strs[i].size() < min_size){
                min_size = strs[i].size();
            }
        }

        if(min_size == 0) return "";

        std::string prefix;
        int start = 0;
        while(start < min_size){
            bool is_same = true;
            for(int i=0;i<size-1;i++){
                if(strs[i][start] != strs[i+1][start]){
                    is_same = false;
                    break;
                }
            }
            if(is_same){
                prefix.push_back(strs[0][start]);
                start++;
            }
            else{
                break;
            }
        }

        return prefix;
    }

int main(){

    vector<string> strs = {"ab","abc","a"};
    string commonPrefix = longestCommonPrefix(strs);
    cout << commonPrefix << endl;

    return 0;
}