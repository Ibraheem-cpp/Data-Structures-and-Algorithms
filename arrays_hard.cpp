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

vector<int> majority_element_2(int arr[] , int n){

    /*
                        BRUTE FORCE

    vector<int> ans;
    for(int i=0;i<n;i++){
        if(ans.size() == 0 || ans.back() != arr[i]){
            int count = 0;
            for(int j=0;j<n;j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }
            if(count > n/3){
                ans.push_back(arr[i]);
            }
        }

        if(ans.size() == 2){break;} -> an array can at max have two elements that appear more than size/3 times
    }

    return ans;

            Time Complexity -> O(n x n)
            Space Complexity -> O(2) -> O(1)
    */


    
    /*
                        BETTER APPROACH

    vector<int> ans;
    std::map<int,int> hashmap;

    for(int i=0;i<n;i++){
        hashmap[arr[i]]++;
        if(hashmap[arr[i]] > n/3){
            if(ans.size() == 0 || ans.back() != arr[i]){
                ans.push_back(arr[i]);
            }
        }
        if(ans.size() == 2){break;}
    }

    return ans;

            Time Complexity -> O(n x log n)
            Space Complexity -> O(n)
    */
}

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    print(arr,n);

    vector<int> maj_element = majority_element_2(arr,n);

    print(maj_element);

    return 0;
}