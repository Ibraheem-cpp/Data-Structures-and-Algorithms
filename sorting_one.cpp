#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void selection_sort(int arr[] , int n){

    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            } 
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    //      Time Complexity -> O(n x n)
    //      Space Complexity -> O(1)

}

void bubble_sort(int arr[] , int n){

    for(int i=0;i<n-1;i++){
        bool did_swap = false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                did_swap = true;
            }
        }
        if(!did_swap){break;}
    }
    
    //      Time Complexity -> O(n x n)
    //      Space Complexity -> O(1)
}

void insertion_sort(int arr[] , int n){

    for(int i=0;i<n;i++){
        int j = i;
        while(j >= 1 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    //      Time Complexity -> O(n x n)
    //      Space Complexity -> O(1)
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    print(arr,n);

    insertion_sort(arr,n);

    print(arr,n);

    return 0;
}