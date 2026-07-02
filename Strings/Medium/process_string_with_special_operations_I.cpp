#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(string& s, int start, int end){
        while(start <= end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
}

string processStr(string s) {
        string result;
        int size = s.length();
        for(int i=0;i<size;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                result.push_back(s[i]);
            }
            else if(s[i] == '*'){
                if(result.length() > 0) result.pop_back();
            }
            else if(s[i] == '#'){
                result.append(result);
            }
            else if(s[i] == '%'){
                if(result.length() > 0) reverse(result, 0, result.length()-1);
            }
        }

        return result;

        //      Time Complexity -> O(2^n) 
        //      Space Complexity -> O(2^n)

        /*          we write 2^n because whenever we see '#' we double the current string
                    meaning that the string is growing exponentially and because the reverse()
                    time will also increase as size increases
        */

}

int main(){

    /*
        Constraints:
            1 <= s.length <= 20
            s consists of only lowercase English letters and special characters *, #, and %.
    */

    string s = "fb*h#n%";
    cout << processStr(s) << endl;

    return 0;
}