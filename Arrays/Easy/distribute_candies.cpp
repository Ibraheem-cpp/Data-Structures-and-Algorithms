#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int>& candyType) {
        int size = candyType.size();
        int toEat = size/2;
        unordered_set<int> hashSet;
        for(int num : candyType){
            hashSet.insert(num);
        }
        int types = hashSet.size();

        if(types <= toEat) return types;

        return toEat;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)
}

int main(){

    /*
        Constraints:
            n == candyType.length
            2 <= n <= 10^4
            n is even.
            -10^5 <= candyType[i] <= 10^5
    */

    vector<int> candyTypes = {1,1,2,2,3,3,3};
    cout << distributeCandies(candyTypes) << endl;

    return 0;
}