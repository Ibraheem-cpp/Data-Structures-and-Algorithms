#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int size = image.size();
        for(int i=0;i<size;i++){
            int start = 0, end = size-1;
            while(start < end){
                swap(image[i][start], image[i][end]);
                if(image[i][start] == 0) image[i][start] = 1;
                else image[i][start] = 0;
                if(image[i][end] == 0) image[i][end] = 1;
                else image[i][end] = 0;
                start++;
                end--;
            }
        }

        if(size % 2 != 0){
            for(int i=0;i<size;i++){
                if(image[i][size/2] == 1) image[i][size/2] = 0;
                else image[i][size/2] = 1;
            }
        }

        return image;

        //      Time Complexity -> O(n x m)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            n == image.length
            n == image[i].length
            1 <= n <= 20
            images[i][j] is either 0 or 1.
    */

    vector<vector<int>> image = {{1,1,0},{0,0,1},{1,0,1}};
    flipAndInvertImage(image);

    return 0;
}