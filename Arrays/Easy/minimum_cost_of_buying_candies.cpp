#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumCost(vector<int>& cost) {
        int size = cost.size();

        sort(cost.begin(),cost.end());
        int price = 0;
        for(int i=size-1;i>=0;i-=3){
            price += cost[i];
            if(i-1 >= 0){price += cost[i-1];}
        }

        return price;

        //      Time Complexity -> O(n log n) + O(n)
        //      Space Complexity -> O(log n) : due to sorting
}

int main(){

    vector<int> candies = {5,5,5,5};
    cout << minimumCost(candies) << endl;

    return 0;
}