#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int totalWaviness(int num1, int num2) {
        vector<int> digits;
        int waviness = 0;
        
        for(int num=num1;num <= num2;num++){
            if(num >= 100){
                digits.clear();
                int temp = num;
                while(temp > 0){
                    int digit = temp % 10;
                    digits.push_back(digit);
                    temp = temp / 10;
                }

                int peak = 0, valley = 0;
                int size = digits.size();
                for(int i=1;i<size-1;i++){
                    if(digits[i] > digits[i-1] && digits[i] > digits[i+1]) peak++;
                    else if(digits[i] < digits[i-1] && digits[i] < digits[i+1]) valley++;
                }

                waviness += peak + valley;
            }
        }

        return waviness;

        //      Time Complexity -> O(n x d) : n -> numbers in range, d -> no. of digits in number
        //      Space Complexity -> O(d) : we store digits 

        //      Approach : pick a number -> extract digts -> check each digit if it is valley or peak.
        //          This works because according to the constraint, the maximum number can be 100000,
        //          if the numbers become pretty large, we'll have to optimize it
        
}

int main(){

    /*
        Constraints:
            1 <= num1 <= num2 <= 10^5
    */

    int num1 = 123;
    int num2 = 67569;
    cout << totalWaviness(num1, num2) << endl;

    return 0;
}