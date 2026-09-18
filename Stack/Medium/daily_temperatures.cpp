#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> answer(size);
        stack<int> st;

        for(int i=size-1;i>=0;i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();
            if(st.empty()) answer[i] = 0;
            else answer[i] = st.top() - i;
            st.push(i);
        }

        return answer;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            1 <= temperatures.length <= 10^5
            30 <= temperatures[i] <= 100
    */

    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temperatures);

    return 0;
}