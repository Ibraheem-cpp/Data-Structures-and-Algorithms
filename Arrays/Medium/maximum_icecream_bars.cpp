#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
        int max = costs[0];
        int size = costs.size();
        for(int i=1;i<size;i++){
            if(costs[i] > max){
                max = costs[i];
            }
        }

        vector<int> counts(max+1,0);
        for(int i=0;i<size;i++){
            counts[costs[i]]++;
        }

        int j=0,k=0;
        while(k <= max){
            if(counts[k] == 0) k++;
            else{
                costs[j] = k;
                j++;
                counts[k]--;
            }
        }

        int bars = 0;
        for(int i=0;i<size;i++){
            if(costs[i] <= coins){
                bars++;
                coins -= costs[i];
            }
            else break;
        }

        return bars;

        //      Time Complexity -> O(n + max(costs)) : because of counting sort
        //      Space Complexity -> O(max(costs)) : because we are using counting sort
}

int main(){

    /*
        Constraints:
            costs.length == n
            1 <= n <= 10^5
            1 <= costs[i] <= 10^5
            1 <= coins <= 10^8
    */

    int coins = 20;
    vector<int> costs = {5,7,12,33,12};
    cout << maxIceCream(costs, coins) << endl;

    return 0;
}