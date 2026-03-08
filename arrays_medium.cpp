#include<bits/stdc++.h>
using namespace std;

void merge(int arr[] , int low , int mid , int high){
    std::vector<int> v1;
    int p1 = low;
    int p2 = mid+1;

    while(p1 <= mid && p2 <= high){
        if(arr[p1] <= arr[p2]){
            v1.push_back(arr[p1]);
            p1++;
        }
        else{
            v1.push_back(arr[p2]);
            p2++;
        }
    }

    while(p1 <= mid){
        v1.push_back(arr[p1]);
        p1++;
    }
    while(p2 <= high){
        v1.push_back(arr[p2]);
        p2++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = v1[i-low];
    }
}

void merge_sort(int arr[] , int low , int high){
    if(low >= high){return;}

    int mid = (low+high)/2;

    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

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

void print(std::vector<vector<int>> mat, int r , int c){
    for(int i=0;i<r;i++){
        cout << "| ";
        for(int j=0;j<c;j++){
            cout << mat[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

void print_sub_array(int arr[] , int start , int end){
    cout << "[ ";
    for(int i=start;i<=end;i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

template<typename T>
void swapp(T& a , T& b){
    T temp = a;
    a = b;
    b = temp;
}

bool two_sum_variant_1(int arr[] , int n , int k){

    /*
                    BRUTE FORCE

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == k){
                return true;
            }
        }
    }

    return false;

        Time Complexity -> O(n x n)
        Space Complexity -> O(1)
    */


    /*
                    BETTER APPROACH

    std::map<int , int> hashmap;
    
    for(int i=0;i<n;i++){
        int x = k - arr[i];
        if(hashmap.find(x) != hashmap.end()){
            return true;
        }
        hashmap[arr[i]] = i;
    }

    return false;

            Time Complexity -> O(n) + O(log n)
            Space Complexity -> O(1)
    */


    //          BETTER APPROACH

    merge_sort(arr,0,n-1);

    int left = 0 , right = n-1;

    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == k){
            return true;
        }
        else if(sum < k){
            left++;
        }
        else{
            right--;
        }
    }

    return false;

    //      Time Complexity -> O(n) + O(n log n)
    //      Space Complexity -> O(1) or O(n) if distortion of array is considered extra space

}

vector<int> two_sum_variant_2(int arr[] , int n , int k){

    /*
                BRUTE FORCE

    std::vector<int> v1;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == k){
                v1.push_back(i);
                v1.push_back(j);
                return v1;
            }
        }
    }

    return {-1,-1};

            Time Complexity -> O(n x n)
            Space Complexity -> O(1)
    */


    
        //            OPTIMAL APPROACH

    std::vector<int> v1;
    std::map<int , int> hashmap;

    for(int i=0;i<n;i++){
        int x = k - arr[i];
        if(hashmap.find(x) != hashmap.end()){
            v1.push_back(hashmap[x]);
            v1.push_back(i);
            return v1;
        }
        hashmap[arr[i]] = i;
    }

    return {-1,-1};

        //    Time Complexity -> O(n) + O(log n)
        //    Space Complexity -> O(n)
    
}

int majority_element_in_array(int arr[] , int n){

    /*
                    BRUTE FORCE

    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n/2){
            return arr[i];
        }
    }

        return -1;

        Time Complexity -> O(n x n)
        Space Complexity -> O(1)
    */


    /*
                    BETTER APPROACH

    std::map<int , int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] > n/2){
            return arr[i];
        }
    }

    return -1;

        Time Complexity -> O(n log n)
        Space Complexity -> O(n)
    */

    
    //              OPTIMAL APPROACH
    //              MOORE's VOTING ALGORITHM
    
    /* select a candidate and maintain its votes
    iterate through the array , if the votes(count) is zero, the current 
    element is selected as candidate, if the same element occurs, increase
    the count, if different element occurs, decreease the count.
    At the end, if the array is confirmes to have a majority element, the
    last man standing is the majority element, otherwise iterate through
    the array again to cross check that the last standing really is the
    majority element.
    */

    int element , count = 0;
    for(int i=0;i<n;i++){
        if(count == 0){
            element = arr[i];
            count++;
        }
        else if(arr[i] == element){
            count++;
        }
        else{
            count--;
        }
    }

    count = 0;

    for(int i=0;i<n;i++){
        if(arr[i] == element){
            count++;
        }
    }

    if(count > n/2){
        return element;
    }
    
    return -1;

    //      Time Complexity -> O(n) + O(n)
    //      Space Complexity -> O(1)
    
}

void sort_array_of_0_1_2(int arr[] , int n){

    /*
                BRUTE FORCE

        merge_sort(arr,0,n-1);

            Time Complexity -> O(n log n)
            Space Complexity -> O(n)
    */


    /*
                BETTER APPROACH

    int count_0 = 0 , count_1 = 0 , count_2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            count_0++;
        }
        else if(arr[i] == 1){
            count_1++;
        }
        else{
            count_2++;
        }
    }

    for(int i=0;i<n;i++){
        if(i >= 0 && i < count_0){
            arr[i] = 0;
        }
        else if(i >= count_0 && i < (count_0 + count_1)){
            arr[i] = 1;
        }
        else{
            arr[i] = 2;
        }
    }

          Time Complexity -> O(n) + O(n)
          Space Complexity -> O(1)

    */


    //          OPTIMAL APPROACH
    //          DUTCH NATIONAL FLAG ALGORITHM (DNF)

    /*
        0 -> low-1 = 0
        low -> mid-1 = 1
        mid -> high = unsorted
        high+1 -> n-1 = 2
    */

    int low = 0 , mid = 0 , high = n-1;

    while(mid <= high){
        if(arr[mid] == 0){
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }

    //      Time Complexity -> O(n)
    //      Space Complexity -> O(1)

}

long long int maximum_subarray_sum(int arr[] , int n){

    /*
                    BRUTE FORCE

    long long int max_sum = INT_MIN;
    long long int current_sum;

    for(int i=0;i<n;i++){
        current_sum = 0;
        for(int j=i;j<n;j++){
            current_sum = current_sum + arr[j];
            if(current_sum >= max_sum){
                max_sum = current_sum;
            }
        }
    }
   
    return max_sum;

        Time Complexity -> O(n x n)
        Space Complexity -> O(1)
    */



    
        //            OPTIMAL APPROACH
        //            KADANE's ALGORITHM

        /*Don't Carry negative weight, whenever sum becomes zero,
        reinitialize it to zero.
        */

    long long int max_sum = INT_MIN;
    long long int current_sum = 0;
    int temp_start = -1 , end = -1 , start = -1;

    for(int i=0;i<n;i++){
        if(current_sum == 0){
            temp_start = i;
        }

        current_sum = current_sum + arr[i];
        if(current_sum >= max_sum){
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }

        if(current_sum < 0){
            current_sum = 0;
        }
    }
    
    print_sub_array(arr,start,end);
    return max_sum;

    //      Time Complexity -> O(n)
    //      Space Complexity -> O(1)
    

}

void buy_and_sell_stock(int arr[] , int n){

    /*
              BRUTE FORCE

    int buy_day , sell_day , profit = 0;
    
    for(int i=0;i<n-1;i++){
        int largest = INT_MIN;
        int temp_sell;
        for(int j=i+1;j<n;j++){
            if(arr[j] > largest){
                largest = arr[j];
                temp_sell = j;
            }
        }

        int temp_profit = largest - arr[i];
        if(temp_profit > profit){
            profit = temp_profit;
            buy_day = i;
            sell_day = temp_sell;
        }
    }

    buy_day++;
    sell_day++;

    if(profit <= 0){
        cout << "No Transactions Done.\n";
    }
    else{
        cout << "Buy on Day " << buy_day << " and Sell on Day " << sell_day << endl;
    }

    cout << "Profit : " << profit << endl;

          Time Compplexity -> O(n x n)
          Space Complexity -> O(1)
    */


    //              OPTIMAL APPROACH

    int buy_day = 0 , sell_day = 1, profit = 0;
    int min = INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i-1] < min){
            min = arr[i-1];
            buy_day = i-1;
        }
        int temp_profit = arr[i] - min;
        if(temp_profit > profit){
            profit = temp_profit;
            sell_day = i;
        }
    }

    buy_day++;
    sell_day++;

    if(profit <= 0){
        cout << "No Transactions Done.\n";
    }
    else{
        cout << "Buy on Day " << buy_day << " and Sell on Day " << sell_day << endl;
    }

    cout << "Profit : " << profit << endl;

    //      Time Complexity -> O(n)
    //      Space Complexity -> O(1)
          

}

void reArrange_elements_by_Sign_type_1(int arr[] , int n){

    //      NUMBER OF POSITIVE AND NEGATIVE NUMBERS ARE EQUAL

    /*
                    BRUTE FORCE

    int arr_pos[n/2] = {0};
    int arr_neg[n/2] = {0};
    int pos = 0 , neg = 0;

    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            arr_pos[pos] = arr[i];
            pos++;
        }
        else if(arr[i] < 0){
            arr_neg[neg] = arr[i];
            neg++;
        }
    }

    pos = 0 , neg = 0;
    
    for(int i=0;i<n;i++){
        if(i % 2 == 0){
            arr[i] = arr_pos[pos];
            pos++;
        }
        else{
            arr[i] = arr_neg[neg];
            neg++;
        }
    }

          Time Complexity -> O(n) + O(n)
          Space Complexity -> O(n)
    */


    //          OPTIMAL APPROACH

    int res[n] = {0};
    int pos = 0 , neg = 1;

    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            res[pos] = arr[i];
            pos+=2;
        }
        else{
            res[neg] = arr[i];
            neg+=2;
        }
    }

    for(int i=0;i<n;i++){
        arr[i] = res[i];
    }

    //      Time Complexity -> O(n) : copying isn't required for solving
    //      Space Complexity -> O(n)
}

void reArrange_elements_by_Sign_type_2(int arr[] , int n){

    //      NUMBER OF POSITIVE AND NEGATIVE NUMBERS ARE NOT EQUAL

    int positives = 0 , negatives = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            positives++;
        }
        else{
            negatives++;
        }
    }

    int arr_pos[positives] = {0};
    int arr_neg[negatives] = {0};

    int pos = 0 , neg = 0;

    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            arr_pos[pos] = arr[i];
            pos++;
        }
        else if(arr[i] < 0){
            arr_neg[neg] = arr[i];
            neg++;
        }
    }

    int limit;      // limit means how many pairs will be in correct alternate order
    if(positives < negatives){
        limit = positives * 2;
    }
    else{
        limit = negatives * 2;
    }

    pos = 0 , neg = 0;

    for(int i=0;i<limit;i++){
        if(i % 2 == 0){
            arr[i] = arr_pos[pos];
            pos++;
        }
        else{
            arr[i] = arr_neg[neg];
            neg++;
        }
    }

    if(positives > negatives){
        for(int i=limit;i<n;i++){
            arr[i] = arr_pos[pos];
            pos++;
        }
    }
    else{
        for(int i=limit;i<n;i++){
            arr[i] = arr_neg[neg];
            neg++;
        }
    }

    //      Time Complexity -> O(n) + O(n) + O(n)
    //      Space Complexity -> O(n)


}

std::vector<int> leaders_in_Array(int arr[] , int n){

    
    /*                BRUTE FORCE

    std::vector<int> leaders;

    for(int i=0;i<n;i++){
        bool is_leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[i] < arr[j]){
                is_leader = false;
                break;
            }
        }
        if(is_leader){
            leaders.push_back(arr[i]);
        }
    }

    return leaders;

        Time Complexity -> O(n x n)
        Space Complexity -> O(1)
    */


    //              OPTIMAL APPROACH

    std::vector<int> leaders;

    int max = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i] > max){
            leaders.push_back(arr[i]);
            max = arr[i];
        }
    }

    int size = leaders.size();
    for(int i=0;i<size/2;i++){
        swapp(leaders[i],leaders[size-i-1]);
    }
    
    return leaders;

    //      Time Complexity -> O(n)
    //      Space Complexity -> O(1) : we are using space to only return, not solve

}

int count_subArrays_with_given_sum(int arr[] , int n , int k){

    
    /*                BRUTE FORCE

    int count = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum = sum + arr[j];
            if(sum == k){
                count++;
            }

        }
        
    }

    return count;

            Time Complexity -> O(n x n)
            Space Complexity -> O(1)

    */



    //              OPTIMAL APPROACH
    std::map<int,int> mpp;
    
    int count = 0 , sum = 0;

    mpp[0] = 1;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];

        int rem = sum - k;

        if(mpp.find(rem) != mpp.end()){
            count = count + mpp[rem];
        }

        mpp[sum]++;
    }

    return count;

    //      Time Complexity -> O(n log n)
    //      Space Complexity -> O(n)
}


bool linear_search(int arr[] , int n , int x){
    for(int i=0;i<n;i++){
        if(arr[i] == x){
            return true;
        }
    }
    
    return false;
}
int longest_consecutive_sequence(int arr[] , int n){
    if(n == 0) return 0;

    /*
                    BRUTE FORCE

    int max_count = 1;

    for(int i=0;i<n;i++){
        int x = arr[i];
        int count = 1;

        while(linear_search(arr,n,x+1)){
            count++;
            x++;
        }

        if(count >= max_count){
            max_count = count;
        }
    }

    return max_count;

            Time Complexity -> O(n x n)
            Space Complexity -> O(1)

    */


    /*
                    BETTER APPROACH

    merge_sort(arr,0,n-1);

    int count = 1 , max_count = 1;

    for(int i=0;i<n-1;i++){
        if(arr[i] == arr[i+1]){continue;}

        if(arr[i] == arr[i+1] - 1){
            count++;
            if(count >= max_count){
                max_count = count;
            }
        }
        else{
            count = 1;
        }
    }

    return max_count;

            Time Complexity -> O(n log n) + O(n)
            Space Complexity -> O(n)

    */


    //              OPTIMAL APPROACH

    int max_count = 1;
    std::unordered_set<int> s1;
    for(int i=0;i<n;i++){
        s1.insert(arr[i]);
    }

    for(auto it : s1){
        if(s1.find(it - 1) == s1.end()){
            int count = 1;
            int x = it;
            while(s1.find(x+1) != s1.end()){
                count++;
                x++;
            }

            if(count >= max_count){
                max_count = count;
            }
        }
    }

    return max_count;

    //      Time Complexity -> O(n) + O(n) : average time for unordered set is O(1), but in worst case it can go to O(n), in which case this approach is not good
    //      Space Complexity -> O(n)
    
}

void spiral_traversal_of_matrix(std::vector<std::vector<int>> mat, int r , int c){
    cout << "Spiral Traversal : " << endl;

    int left = 0;
    int top = 0;
    int right = c-1;
    int bottom = r-1;

    while(left <= right && top <= bottom){
        for(int i=left;i<=right;i++){
            cout << mat[top][i] << " ";
        }
        top++;

        for(int i=top;i<=bottom;i++){
            cout << mat[i][right] << " ";
        } 
        right--;

        if(top <= bottom){
            for(int i=right;i>=left;i--){
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }
 
        if(left <= right){
            for(int i=bottom;i>=top;i--){
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }

    //      Time Complexity -> O(r x c)
    //      Space Complexity -> O(1)
}

void rotate_matrix_90_degrees(std::vector<std::vector<int>> &mat, int r , int c){

    /*
                    BRUTE FORCE

    std::vector<std::vector<int>> mat2;
    int r2 = c;
    int c2 = r;

    for(int i=0;i<r2;i++){
        std::vector<int> row;
        for(int j=0;j<c2;j++){
            row.push_back(mat[j][i]);
        }
        mat2.push_back(row);
    }

    for(int i=0;i<r2;i++){
        for(int j=0;j<c2/2;j++){
            swapp(mat2[i][j],mat2[i][c2-j-1]);
        }
    }
    

    print(mat2,r2,c2);
        Time Complexity -> O(r x c) + O(c x r/2) -> Simplifies to O(r x c)
        Space Complexity -> O(r x c)

    */



    //                  OPTIMAL APPROACH 
    //  -> Only for square matrices

    for(int i=0;i<r-1;i++){
        for(int j=i+1;j<c;j++){
            swapp(mat[i][j] , mat[j][i]);
        }
    }
    //  -> we visit almost half elements ((n^2 - n)/2) -> O(n^2) -> O(r x c)

    for(int i=0;i<r;i++){
        for(int j=0;j<c/2;j++){
            swapp(mat[i][j] , mat[i][c-j-1]);
        }
    }


    //      Time Complexity -> O(r x c) + O(r x c/2) -> Simplifies to O(r x c)
    //      Space Complexity -> O(1)

}

void set_row(std::vector<std::vector<int>> &mat, int i , int c){
    for(int j=0;j<c;j++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}
void set_column(std::vector<std::vector<int>> &mat, int r , int j){
    for(int i=0;i<r;i++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}
void set_matrix_zeroes(std::vector<std::vector<int>> &mat, int r , int c){

    /*
                    BRUTE FORCE

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j] == 0){
                set_row(mat,i,c);
                set_column(mat,r,j);
            }
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }
            Time Complexity -> O((r x c)x(r + c)) + O(r x c)
            Space Complexity -> O(1)

    */


    /*
                    BETTER APPROACH

    int row[r] = {0};
    int col[c] = {0};

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(row[i] == 1 || col[j] == 1){
                mat[i][j] = 0;
            }
        }
    }
        Time Complexity -> O(r x c) + O(r x c)
        Space Complexity -> O(r + c)

    */

    
}

int main(){

    int r,c,n;
    cin >> r >> c;

    std::vector<std::vector<int>> mat;

    for(int i=0;i<r;i++){
        std::vector<int> row;
        for(int j=0;j<c;j++){
            cin >> n;
            row.push_back(n);
        }
        mat.push_back(row);
    }

    print(mat,r,c);

    set_matrix_zeroes(mat,r,c);

    print(mat,r,c);


    return 0;
}