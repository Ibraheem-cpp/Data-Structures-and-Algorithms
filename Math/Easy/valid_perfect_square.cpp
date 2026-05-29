#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num) {
        for(long long int i=0;i*i<=num;i++){
            if(i*i == num) return true;
        }

        return false;
}

int main(){

    int num = 49;
    if(isPerfectSquare(num)){
        cout << "Yes.\n";
    }
    else{
        cout << "No.\n";
    }

    return 0;
}