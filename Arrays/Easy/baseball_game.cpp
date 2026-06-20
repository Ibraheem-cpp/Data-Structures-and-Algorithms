#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& operations) {
        int size = operations.size();
        vector<int> scores;

        for(int i=0;i<size;i++){
            if(operations[i] == "+"){
                int n = scores.size();
                scores.push_back(scores[n-1] + scores[n-2]);
            }
            else if(operations[i] == "D"){
                scores.push_back(2 * scores.back());
            }
            else if(operations[i] == "C"){
                scores.pop_back();
            }
            else{
                scores.push_back(stoi(operations[i]));
            }
        }

        int sum = 0;
        for(int num : scores) sum += num;

        return sum;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(n)

}

int main(){

    /*
        Constraints:
            1 <= operations.length <= 1000
            operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
            For operation "+", there will always be at least two previous scores on the record.
            For operations "C" and "D", there will always be at least one previous score on the record.
    */

    vector<string> ops = {"4", "D", "C", "3", "+"};
    cout << calPoints(ops) << endl;

    return 0;
}