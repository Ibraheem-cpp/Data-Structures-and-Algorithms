#include<bits/stdc++.h>
using namespace std;

int count_digits(int n){
    int count = 0;
    while(n > 0){
        n = n/10;
        count++;
    }

    // count = int(log10(n) + 1);  --> another method

    return count;
}

int reverse_number(int n){
    int rev = 0;
    while(n > 0){
        int last_digit = n % 10;
        rev = (rev*10) + last_digit;
        n = n/10;
    }

    return rev;
}

bool is_palindrome(int n){
    if(n == reverse_number(n)){
        return true;
    }

    return false;
}

bool is_armstrong(int n){
    int temp = n, temp_1 = 0;
    while(n > 0){
        int digit = n % 10;
        temp_1 = temp_1 + (digit * digit * digit);
        n = n/10;
    }

    if(temp == temp_1){return true;}
    return false;
}

void all_divisors(int n){

    vector<int> divisors;

    for(int i=1 ; i*i<=n ; i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(n/i != i){
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(),divisors.end());
    for(auto i : divisors){
        cout << i << " ";
    }
    cout << endl;
}

bool is_prime(int n){
    if(n <= 1){return false;}

    for(int i=2 ; i*i<=n ; i++){
        if(n%i == 0){return false;}
    }

    return true;
}

int GCD_HCF(int n1 , int n2){

    while(n1 > 0 && n2 > 0){
        if(n1 > n2){n1 = n1 % n2;}
        else{n2 = n2 % n1;}
    }

    if(n1 == 0){return n2;}
    return n1;
    
}

int main(){

    int n;
    cin >> n;

    cout << GCD_HCF(544,544);

    return 0;
}