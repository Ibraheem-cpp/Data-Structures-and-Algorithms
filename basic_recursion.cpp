#include<bits/stdc++.h>
using namespace std;


void print_name_n_times(string name , int count , int n){
    if(count > n) return;
    
    cout << name << endl;
    print_name_n_times(name,count+1,n);
}

void print_1_to_n_forward(int num , int n){
    if(num > n) return;

    cout << num << " ";
    print_1_to_n_forward(num+1,n);
}

void print_1_to_n_backtrack(int num){
    if(num < 1) return;
    
    print_1_to_n_backtrack(num-1);
    cout << num << " ";
}

void print_3(int num){
    if(num < 1) return;

    print_3(num-1);
    cout << num << endl;
}

void print_4(int i , int num){
    if(i > num) return;

    print_4(i+1,num);
    cout << i << endl;
}

int recursion_sum(int num){
    if(num == 1) return 1;

    return num + recursion_sum(num-1);
}  

int recursion_factorial(int num){
    if(num == 1) return 1;

    return num * recursion_factorial(num - 1);
}

void recursive_reverse_array(int arr[] , int i , const int size){
    if(i >= size/2) return;

    int temp = arr[i];
    arr[i] = arr[size-i-1];
    arr[size-i-1] = temp;

    recursive_reverse_array(arr , i+1 , size);
}

bool is_palindrome_array(int arr[] , int i , int size){
    if(i >= size/2) return true;

    if(arr[i] != arr[size-1-i]) return false;

    return is_palindrome_array(arr,i+1,size);
}

bool is_palindrome_string(const string& s , int i){
    if(i >= s.size() / 2) return true;

    if(s[i] != s[s.size() - i - 1]) return false;
    
    return is_palindrome_string(s,i+1);
}

int recurive_fibonacci(int n){
    if(n <= 1) return n;

    int last = recurive_fibonacci(n-1);
    int sec_last = recurive_fibonacci(n-2);

    return last + sec_last;
}

int main(){

    int arr[6] = {1,2,3,3,2,1};
    if(is_palindrome_array(arr,0,6)){
        cout << "Yes.\n";
    }
    else{
        cout << "No.\n";
    }

    return 0;
}