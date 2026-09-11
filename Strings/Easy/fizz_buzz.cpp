#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(i % 3 == 0 && i % 5 == 0) ans.push_back("FizzBuzz");
            else if(i % 5 == 0) ans.push_back("Buzz");
            else if(i % 3 == 0) ans.push_back("Fizz");
            else ans.push_back(to_string(i));
        }

        return ans;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            1 <= n <= 10^4
    */

    int n = 20;
    vector<string> ans = fizzBuzz(n);

    return 0;
}