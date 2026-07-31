#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int passThePillow(int n, int time) {
        int second = 1;
        int person = 1;
        int direction = 1;
        while(second <= time){
            if(person == 1) direction = 1;
            else if(person == n) direction = -1;
            person += direction;
            second++;
        }

        return person;

        //      Time Complexity -> O(time)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            2 <= n <= 1000
            1 <= time <= 1000
    */

    int n = 10;
    int time = 200;
    cout << passThePillow(n,time) << endl;

    return 0;
}