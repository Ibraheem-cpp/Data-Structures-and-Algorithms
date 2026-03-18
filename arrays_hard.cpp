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



    //                  OPTIMAL APPROACH
    //  Moore's Voting Algorithm with some tweeks 

    int element1 = 0 , element2 = 0;
    int count1 = 0 , count2 = 0;

    for(int i=0;i<n;i++){
        if(count1 == 0 && arr[i] != element2){
            element1 = arr[i];
            count1 = 1;
        }
        else if(count2 == 0 && arr[i] != element1){
            element2 = arr[i];
            count2 = 1;
        }
        else if(arr[i] == element1){
            count1++;
        }
        else if(arr[i] == element2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    count1 = 0 , count2 = 0;

    for(int i=0;i<n;i++){
        if(arr[i] == element1){
            count1++;
        }
        else if(arr[i] == element2){
            count2++;
        }
    }

    vector<int> ans;
    if(count1 > n/3){
        ans.push_back(element1);
    }
    if(count2 > n/3 && element2 != element1){
        ans.push_back(element2);
    }

    return ans;

    //      Time Complexity -> O(n) + O(n)
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

    vector<int> maj_element = majority_element_2(arr,n);

    print(maj_element);

    return 0;
}