#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols  = rows;

        for(int i=0;i<rows;i++){
            for(int j=i+1;j<cols;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols/2;j++){
                swap(matrix[i][j], matrix[i][cols-j-1]);
            }
        }

        //      Time Complexity -> O(n x n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            n == matrix.length == matrix[i].length
            1 <= n <= 20
            -1000 <= matrix[i][j] <= 1000
    */

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    for(vector vec : matrix){
        for(int num : vec){
            cout << num << " ";
        }
        cout << endl;
    }

    rotate(matrix);
    for(vector vec : matrix){
        for(int num : vec){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}