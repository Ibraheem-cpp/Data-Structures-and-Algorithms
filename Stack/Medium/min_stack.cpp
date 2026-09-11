#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinStack {
    vector<int> vec;
    vector<int> minVec;
public:
    MinStack() {

    }
    
    void push(int value) {
        vec.push_back(value);
        if(minVec.size() == 0) minVec.push_back(value);
        else{
            if(value <= minVec.back()) minVec.push_back(value);
        }
    }
    
    void pop() {
        if(vec.back() == minVec.back()){
            vec.pop_back();
            minVec.pop_back();
        }
        else vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return minVec.back();
    }
};

/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

        //      Time Complexity -> O(1)
        //      Space Complexity -> O(n)

int main(){

    /*
        Constraints:
            -2^31 <= val <= 2^31 - 1
            Methods pop, top and getMin operations will always be called on non-empty stacks.
            At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
    */

    return 0;
}