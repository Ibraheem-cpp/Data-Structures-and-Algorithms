#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<long long> sumOfThree(long long num) {
        long long int second = num/3;

        if(second * 3 == num) return {second-1, second, second+1};

        return {};

        //      Time Complexity -> O(1)
        //      Space Complexity -> O(1)
}

int main(){

    long long num = 33;
    vector<long long> ans = sumOfThree(num);

    return 0;
}