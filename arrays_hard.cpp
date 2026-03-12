#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void print(std::vector<int> v1){
    cout << "[ ";
    for(int i=0;i<v1.size();i++){
        cout << v1[i] << " ";
    }
    cout << "]" << endl;
}

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    print(arr,n);

    return 0;
}