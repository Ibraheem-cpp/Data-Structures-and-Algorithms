#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void merge(int arr[] , int low , int mid , int high){
    int temp[high+1] = {0};
    int start = low;
    int end = mid+1;
    int i=0;

    while(start <= mid && end <= high){
        if(arr[start] <= arr[end]){
            temp[i] = arr[start];
            start++;
            i++;
        }
        else{
            temp[i] = arr[end];
            end++;
            i++;
        }
    }

    while(start <= mid){
        temp[i] = arr[start];
        start++;
        i++;
    }
    while(end <= high){
        temp[i] = arr[end];
        end++;
        i++;
    }

    for(auto i : temp){
        cout << i << " ";
    }

    cout << endl;
    for(int j=low;j<=high;j++){
        arr[j] = temp[j-low];
    }
}

void merge_sort(int arr[] , int low , int high){
    if(low >= high){return;}

    int mid = (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);

    //      Time Complecity -> O(n log n)
    //      Space Complexity -> O(n)
}

void recursive_bubble_sort(int arr[] , int n){
    if(n <= 1 ) return;

    bool did_swap = false;

    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            did_swap = true;
        }
    }

    if(!did_swap){return;}

    recursive_bubble_sort(arr,n-1);
}

void recursive_selection_sort(int arr[] , int start , int size){
    if(start >= size-1) return;

    int min_index = start;
    for(int i=start+1;i<size;i++){
        if(arr[i] < arr[min_index]){
            min_index = i;
        }
    }
    int temp = arr[start];
    arr[start] = arr[min_index];
    arr[min_index] = temp;
    
    recursive_selection_sort(arr,start+1,size);
}

void recursive_insertion_sort(int arr[] , int start , int size){
    if(start >= size) return;

    int i = start;
    while(arr[i] < arr[i-1] && i > 0){
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
        i--;
    }

    recursive_insertion_sort(arr,start+1,size);

}

int quick_sort_parts(int arr[] , int low , int high){
    int pivot = arr[low];
    int i = low , j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high){i++;}
        while(arr[j] > pivot && j >= low){j--;}
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int arr[] , int low , int high){
    if(low >= high) return;

    int partition = quick_sort_parts(arr,low,high);

    quick_sort(arr,low,partition-1);
    quick_sort(arr,partition+1,high);

    //      Time Complecity -> O(n log n)
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
    quick_sort(arr,0,n-1);
    print(arr,n);

    return 0;
}
