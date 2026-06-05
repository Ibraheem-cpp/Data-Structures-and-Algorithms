#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
        int size1 = g.size();
        int size2 = s.size();
        int i = 0, j = 0;
        int content = 0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(i < size1 && j < size2){
            if(s[j] >= g[i]){
                content++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return content;

        //      Time Complexity -> O(n log n) + O(n log n) : due to sorting
        //      Space Complexity -> O(log n) + O(log n) : due to sorting

        //      Approach : Sorting and two pointer
}

int main(){

    vector<int> children = {2,4,6,7};
    vector<int> cookies = {3,4,5};
    cout << findContentChildren(children,cookies) << endl;

    return 0;
}