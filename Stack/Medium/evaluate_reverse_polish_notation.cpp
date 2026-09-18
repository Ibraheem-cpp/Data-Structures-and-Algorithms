#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(string& ch : tokens){
            if(ch == "+"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(num1+num2);
            }
            else if(ch == "-"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(num1-num2);
            }
            else if(ch == "*"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(num1*num2);
            }
            else if(ch == "/"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(num1/num2);
            }
            else st.push(stoi(ch));
        }

        return st.top();

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            1 <= tokens.length <= 10^4
            tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
    */

    vector<string> tokens = {"2","1","+","3","*"};
    cout << evalRPN(tokens) << endl;

    return 0;
}