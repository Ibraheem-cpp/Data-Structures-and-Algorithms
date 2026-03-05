#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int largest_element_in_array(int arr[] , int n){

    /*
                    BRUTE FORCE
        first sort
        largest element at n-1 index
        Time Complexity -> O(n log n) : due to sorting
    */


    //          OPTIMAL APPROACH

    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > largest){       // --> Time Complexity : O(n)
            largest = arr[i];
        }
    }

    return largest;
}

int second_largest_element(int arr[] , int n){
    
    /*            BRUTE FORCE
        first sort
        int largest = arr[n-1];
        int second_largest = INT_MIN;
        for(int i=n-2;i>=0;i--){
            if(arr[i] != largest){
                second_largest = arr[i];
            }
        }
            Time Complexity -> O(n) + O(n log n)
    */

    
    /*         BETTER APPROACH
        int largest = largest_element_in_array(arr,n);
        int second_largest = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i] > second_largest && arr[i] != largest){
                second_largest = arr[i];
            }
        }
            Time Complexity -> O(n) + O(n)
    */


    //      OPTIMAL APPROACH
        int second_largest = INT_MIN;
        int largest = arr[0];

        for(int i=1;i<n;i++){
            if(arr[i] > largest){
                second_largest = largest;
                largest = arr[i];
            }
            else if(arr[i] > second_largest && arr[i] != largest){
                second_largest = arr[i];
            }
        }
            // Time Complexity -> O(n)


        return second_largest;
    
}

int smallest_element_in_array(int arr[] , int n){

    /*
                    BRUTE FORCE
        first sort
        smallest element at 0 index
        Time Complexity -> O(n log n) : due to sorting
    */


    //          OPTIMAL APPROACH

    int smallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i] < smallest){       // --> Time Complexity : O(n)
            smallest = arr[i];
        }
    }

    return smallest;
}

bool is_array_sorted(int arr[] , int n){
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            return false;           // Time Complexity -> O(n)
        }
    }

    return true;
}

void remove_duplicates(int arr[] , int n){

    /*          BRUTE FORCE
    std::set<int> s1;

    for(int i=0;i<n;i++){
        s1.insert(arr[i]);
    }

    int count = 0;

    for(auto i : s1){
        arr[count] = i;
        count++;
    }
        Time Complexity -> O(n log n) + O(n)
    */


    //          OPTIMAL APPROACH

    /*
            MY METHOD
    int count = 1 , j = 1;

    for(int i=0;i<n && j<n;i++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            j++;
            count++;
        }
        else{
            i--;
            j++;
        }
    }
        Time Complexity -> O(n)
    */

    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    int count = i+1;

    print(arr,count);
}

void left_rotate_array_by_one(int arr[] , int n){

    /*          BRUTE FORCE 
        int temp[n];
        for(int i=0;i<n-1;i++){
            temp[i] = arr[i+1];
        }
        temp[n-1] = arr[0];

        for(int i=0;i<n;i++){
            arr[i] = temp[i];
        }
            Time Complexity -> O(n) + O(n)
    */

    //          OPTIMAL APPROACH
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;

    //      Time Complexity -> O(n)
}

void reverse_array(int arr[] , int start , int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++,end--;
    }
}

void left_rotate_array_by_k(int arr[] , int n , int d){
    d = d % n;

    /*
                    BRUTE FORCE
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    }

    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }

    for(int i=n-d;i<n;i++){
        arr[i] = temp[i-(n-d)];
    }
        Time Complexity -> O(d) + O(n-d) + O(d)
        Space Complexity -> O(n) : due to temporary array
    */


    //          OPTIMAL APPROACH

    reverse_array(arr,0,d-1);   // --> first reverse first d elements 

    reverse_array(arr,d,n-1);   // --> then reverse elements from d to n

    reverse_array(arr,0,n-1);   // --> then reverse the whole array

    //      Time Complexity -> O(d) + O(n-d) + O(n)
    //      Space Complexity -> O(1) : using the original array, no extra space used


}

void right_rotate_array_by_one(int arr[] , int n){
    int temp = arr[n-1];
    for(int i=n-2;i>=0;i--){
        arr[i+1] = arr[i];
    }

    arr[0] = temp;
}

void right_rotate_array_by_k(int arr[] , int n , int d){

    /*
                    BRUTE FORCE
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i] = arr[n-d+i];
    }

    for(int i=n-d-1;i>=0;i--){
        arr[i+d] = arr[i];
    }

    for(int i=0;i<d;i++){
        arr[i] = temp[i];
    }
    */


    //              OPTIMAL APPROACH

    reverse_array(arr,0,n-1);

    reverse_array(arr,0,d-1);

    reverse_array(arr,d,n-1);
}

void move_zeroes_to_end(int arr[] , int n){

    /*
                    BRUTE FORCE
    int temp[n] = {0};
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            temp[j] = arr[i];
            j++;
        }
    }

    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
            Time Complexity -> O(n) + O(n)
            Space Complexity -> O(n)
    */


    //              OPTIMAL APPROACH
    
    int k = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            k = i;
            break;
        }
    }

    if(k == -1){return;}

    for(int j=k+1;j<n;j++){
        if(arr[j] != 0){
            int temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
            k++;
        }
        
    }


}

int linear_search(int arr[] , int n , int target){
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            return i;
        }
    }

    return -1;
}

void union_of_two_sorted_arrays(int arr1[] , int n , int arr2[] , int m){
    
    /*
                        BY USING SET
    std::set<int> s1;

    for(int i=0;i<n;i++){
        s1.insert(arr1[i]);
    }

    for(int i=0;i<m;i++){
        s1.insert(arr2[i]);
    }

    for(auto it : s1){
        cout << it << " ";
    }
                Time Complexity -> (n+m) log (n+m)
                Space Complexity -> O(n+m)
    */


    //              OPTIMAL APPROACH

    int i=0,j=0;
    std::vector<int> v1;
    int union_array[m+n] = {0};
    int k=0;

    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            if(v1.size() == 0 || arr1[i] != v1.back()){
                v1.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(arr2[j] != v1.back() || v1.size() == 0){
                v1.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i < n){
        if(v1.size() == 0 || arr1[i] != v1.back()){
            v1.push_back(arr1[i]);
        }
        i++;
    }
    while(j < m){
        if(v1.size() == 0 || arr2[j] != v1.back()){
            v1.push_back(arr2[j]);
        }
        j++;
    }

    for(auto it : v1){
        cout << it << " ";
    }

    //          Time Complexity -> O(n+m)
    //          Space Complexity -> O(n+m)

}

void intersection_of_two_sorted_arrays(int arr1[] , int n , int arr2[] , int m){

    /*
                BRUTE FORCE
    
    std::vector<int> v2;
    int visited[m] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i] == arr2[j] && visited[j] == 0){
                v2.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if(arr1[i] < arr2[j]){break;}
        }
    }

                Time Complexity -> O(n x m)
                Space Complexity -> O(m) + O(min(n,m))
    
    */

    

    //              OPTIMAL APPROACH
    
    std::vector<int> v1;
    int i=0 , j=0;
    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            v1.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            i++;
        }
    }

    for(auto it : v1){
        cout << it << " ";
    }

    //          Time Complexity -> O(n + m)
    //          Space Complexity -> O(min(n,m))
}

int missing_element_in_array(int arr[] , int size , int n){


    /*      
                BRUTE FORCE

    for(int i=1;i<=n;i++){
        bool found = false;
        for(int j=0;j<size;j++){
            if(arr[j] == i){
                found = true;
                break;
            }
        }
        if(!found){return i;}
    }
        Time Complexity -> O(n x n)
    */


    /*

                BETTER APPROACH

    int hash[n+1] = {0};
    for(int i=0;i<size;i++){
        hash[arr[i]] = 1;
    }

    for(int i=1;i<=n;i++){
        if(hash[i] == 0){
            return i;
        }
    }
            Time Complexity -> O(n) + O(n)
            Space Complexity -> O(n)
    */


    /*
                    OPTIMAL APPROACH 1 USING XOR
                    
                    ^ -> XOR symbol
                    a ^ a = 0
                    a ^ 0 = a

    int XOR1 = 0;
    for(int i=1;i<=n;i++){
        XOR1 = XOR1 ^ i;
    }

    int XOR2 = 0;
    for(int i=0;i<size;i++){
        XOR2 = XOR2 ^ arr[i];
    }

    return XOR1 ^ XOR2;

            Time Complexity -> O(n) + O(n)
    */


    //          OPTIMAL APPROACH 2

    int total_sum = (n*(n+1))/2;
    int present_sum = 0;

    for(int i=0;i<size;i++){
        present_sum = present_sum + arr[i];
    }

    int missing_num = total_sum - present_sum;

    return missing_num;

    //      Time Complexity -> O(N)
}

int maximum_consecutive_ones(int arr[] , int size){

    int count = 0 , max_count = 0;

    for(int i=0;i<size;i++){
        if(arr[i] == 1){
            count++;
        }
        else{
            if(count >= max_count){
                max_count = count;
            }
            count = 0;
        }
    }
    if(count >= max_count){
        max_count = count;
    }

    return max_count;

            // Time Complexity -> O(n)
}

int number_that_appears_once(int arr[] , int size){

    /*
                    BRUTE FORCE

    for(int i=0;i<size;i++){
        int count = 0;
        for(int j=0;j<size;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count == 1){
            return arr[i];
        }
    }
            Time Complexity -> O(n x n)

    */


    
    /*            BETTER APPROACH 

            USING HASHING

    int largest = largest_element_in_array(arr,size);
    int hash[largest+1] = {0};

    for(int i=0;i<size;i++){
        hash[arr[i]]++;
    }

    for(int i=0;i<size;i++){
        if(hash[arr[i]] == 1){
            return arr[i];
        }
    }
        Time Complexity -> O(n) + O(n) + O(n)
        Space Complexity -> O(largest array element)

    
            USING MAP

    std::map<long long , int> mpp;

    for(int i=0;i<size;i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
    }
            Time Complexity -> O(n) + O(n log m) : m -> size of set = (n/2) + 1
            Space Complexity -> O((n/2) + 1)

    */

    

    //          OPTIMAL APPROACH USING XOR

    int num = 0;
    for(int i=0;i<size;i++){
        num = num ^ arr[i];
    }

    return num;

    //      Time Complexity -> O(n)
    //      Space Complexity -> O(1)
}

int longest_subarray_with_sum_k_nonNegative(int arr[] , int n , int k){

    /*
                    BRUTE FORCE

    int max_length = 0;
    for(int i=0;i<n;i++){
        int length = 0;
        int sum = 0;
        for(int j=i;j<n;j++){
            sum = sum + arr[j];
            length++;
            if(sum == k){
                if(length >= max_length){
                    max_length = length;
                    break;
                }
                break;
            }
            if(sum > k){
                break;
            }
        }
    }

    return max_length;

            Time Complexity -> O(n x n)
            Space Complexity -> O(1)
    */


    /*
                    BETTER APPROACH

    int max_length = 0;
    long long int sum = 0;
    std::map<long long int , int> hashmap;

    for(int i=0;i<n;i++){
        sum = sum + arr[i];
        if(sum == k){
            if(i+1 >= max_length){
                max_length = i+1;
            }
        }

        long long int rem = sum-k;

        if(hashmap.find(rem) != hashmap.end()){
            int len = i - hashmap[rem];
            if(len >= max_length){
                max_length = len;
            }
        }

        if(hashmap.find(sum) == hashmap.end()){
            hashmap[sum] = i;
        }
    }

    return max_length;

            Time Complexity -> O(n) x O(log n) : log n -> finding in map
            Space Complexity -> O(n)

    */


    //                  OPTIMAL APPROACH
    //      Sliding Window Method
    
    int max_length = 0;
    int i = 0 , j = 0;
    long long int sum = 0;

    while(i < n){
        sum = sum + arr[i];

        while(sum > k && j <= i){
            sum = sum - arr[j];
            j++;
        }
        
        if(sum == k){
            int len = i - j + 1;
            if(len >= max_length){
                max_length = len;
            }
        }

        i++;
    }

    return max_length;

    //      Time Complexity -> O(2n) 
    //      Space Complexity -> O(1)
}


int longest_subarray_with_sum_k_allNumbers(int arr[] , int n , int k){

    /*
                    BRUTE FORCE

    int max_length = 0;
    for(int i=0;i<n;i++){
        int length = 0;
        int sum = 0;
        for(int j=i;j<n;j++){
            sum = sum + arr[j];
            length++;
            if(sum == k){
                if(length >= max_length){
                    max_length = length;
                    break;
                }
                break;
            }
            if(sum > k){
                break;
            }
        }
    }

    return max_length;

            Time Complexity -> O(n x n)
            Space Complexity -> O(1)
    */


    
    //                OPTIMAL APPROACH

    int max_length = 0;
    long long int sum = 0;
    std::map<long long int , int> hashmap;

    for(int i=0;i<n;i++){
        sum = sum + arr[i];
        if(sum == k){
            if(i+1 >= max_length){
                max_length = i+1;
            }
        }

        long long int rem = sum-k;

        if(hashmap.find(rem) != hashmap.end()){
            int len = i - hashmap[rem];
            if(len >= max_length){
                max_length = len;
            }
        }

        if(hashmap.find(sum) == hashmap.end()){
            hashmap[sum] = i;
        }
    }

    return max_length;

        //Time Complexity -> O(n) x O(log n) : log n -> finding in map
        //Space Complexity -> O(n)

    
}

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

   print(arr,n);

   cout << "Length of Longest Sub-Array : " << longest_subarray_with_sum_k_nonNegative(arr,n,10);

    return 0;
}