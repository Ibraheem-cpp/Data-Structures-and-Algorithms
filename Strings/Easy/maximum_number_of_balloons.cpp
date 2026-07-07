#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxNumberOfBalloons(string text) {
        int countB = 0, countA = 0, countL = 0, countO = 0, countN = 0;
        for(char ch : text){
            if(ch == 'b') countB++;
            else if(ch == 'a') countA++;
            else if(ch == 'l') countL++;
            else if(ch == 'o') countO++;
            else if(ch == 'n') countN++;
        }

        countO /= 2;
        countL /= 2;
        int balloons = min({countB, countA, countL, countO, countN});

        return balloons;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            1 <= text.length <= 10^4
            text consists of lower case English letters only.
    */

    string text = "bjkllannoosdgnnvsd";
    cout << maxNumberOfBalloons(text) << endl;

    return 0;
}