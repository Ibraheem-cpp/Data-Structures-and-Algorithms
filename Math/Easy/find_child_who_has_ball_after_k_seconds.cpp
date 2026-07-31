#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numberOfChild(int n, int k) {
        int second = 1;
        int child = 0;
        int direction = 1;
        while(second <= k){
            if(child == 0) direction = 1;
            else if(child == n-1) direction = -1;
            child += direction;
            second++;
        }

        return child;

        //      Time Complexity -> O(k)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            2 <= n <= 50
            1 <= k <= 50
    */

    int n = 5;
    int k = 10;
    cout << numberOfChild(n,k) << endl;

    return 0;
}