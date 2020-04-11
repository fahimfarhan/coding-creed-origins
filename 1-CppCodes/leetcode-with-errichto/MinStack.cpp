#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    const static int CAPACITY = 100000;
    int s[CAPACITY];
    int minimus[CAPACITY];

    int index = -1;

    MinStack() {
        index = -1;
        for(int i=0; i<CAPACITY; i++){
            s[i] = 0;
            minimus[i] = 0;
        }    
    }
    
    void push(int x) {
        index++;
        s[index] = x;
        if(index == 0){
            minimus[index] = x;
        }else{
            minimus[index] = min(minimus[(index-1)], x);
        }

    }
    
    void pop() {
        if(index>=0){   index--; }       
    }
    
    int top() {
        if(index >= 0){ return s[index];    }
        return -1;
    }
    
    int getMin() {
        if(index>=0)
            return minimus[index];      
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

    MinStack minStack; // = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<"\n"; //  --> Returns -3.
    minStack.pop();
    cout<<minStack.top()<<"\n";      // --> Returns 0.
    cout<<minStack.getMin()<<"\n";   // --> Returns -2.
    return 0;
}