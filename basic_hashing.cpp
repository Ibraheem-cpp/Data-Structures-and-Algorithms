#include<bits/stdc++.h>
using namespace std;

void number_hasing_with_array(){
    
    int hash[11] = {0};
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    int q , num;
    cin >> q;

    for(int i=0;i<q;i++){
        cin >> num;
        cout << num << " : " << hash[num] << endl;
    }
}

void character_hashing_with_array(){

    string s;
    cin >> s;
    int hash[256] = {0};

    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }

    int q;
    cin >> q;

    char c;

    for(int i=0;i<q;i++){
        cin >> c;
        cout << c << " : " << hash[c] << endl;
    }
}

void number_hashing_with_map(){
    int max_freq = INT_MIN;
    int min_freq = INT_MAX;
    int max,min;

    int n;
    cin >> n;
    int arr[n] = {0};
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    unordered_map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        if(it.second > max_freq){
            max_freq = it.second;
            max = it.first;
        }

        if(it.second < min_freq){
            min_freq = it.second;
            min = it.first;
        }
    }

    int q,num;
    cin >> q;

    while(q--){
        cin >> num;
        cout << num << " -> " << mpp[num] << endl;
    }

    

    cout << "Max Element : " << max << " -> Frequency : " << max_freq << endl;
    cout << "Min Element : " << min << " -> Frequency : " << min_freq << endl;
}

void character_hashing_with_map(){

    int max_freq = INT_MIN;
    int min_freq = INT_MAX;
    char max,min;

    string s;
    cin >> s;

    map<char,int> mpp;

    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
    }

    for(auto it : mpp){
        if(it.second > max_freq){
            max_freq = it.second;
            max = it.first;
        }

        if(it.second < min_freq){
            min_freq = it.second;
            min = it.first;
        }
    }

    int q;
    char c;
    cin >> q;

    while(q--){
        cin >> c;
        cout << c << " -> " << mpp[c] << endl;
    }

    

    cout << "Max Element : " << max << " -> Frequency : " << max_freq << endl;
    cout << "Min Element : " << min << " -> Frequency : " << min_freq << endl;


}

int main(){

    

    return 0;
}