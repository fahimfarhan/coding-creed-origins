#include <bits/stdc++.h>
using namespace std;
 
#define SIZE 10
 
class Stack{
    int top = -1;
    int* stk;
    int capacity = SIZE;
 
public:
     Stack(){
        stk = new int[capacity];
     }
 
     int getCapacity(){
         return capacity;
     }
 
     void push(int data){
 
        if(top < capacity){
            stk[++top] = data;
        }
        else{
            cout << "in else " << endl;
            int temp[getSize()];
 
            cout << "array created " << endl;
 
            for(int i = 0; i <= top; i++){
                temp[i] = stk[i];
            }
            cout << "value copied" << endl;
 
            capacity += SIZE;
            cout << "cap barailam" << endl;
 
            delete[] stk;
            cout << "delete korlam" << endl;
            stk = new int[capacity];
 
            cout << "increades stack" << endl;
            for(int i = 0; i <= top; i++){
                stk[i] = temp[i];
            }
            cout << "re-copied" << endl;
 
            stk[++top] = data;
        }
     }
 
     int pop(){
         if(!isEmpty()){
             return stk[top--];
         }
         else{
             return -1;
         }
     }
 
     bool isEmpty(){
         return (top < 0);
     }
 
     void print(){
         for(int i = top; i >= 0; i--){
             cout << stk[i] << ", ";
         }
         cout << endl;
     }
 
     int getSize(){
         return top + 1;
     }
 
};
 
int main(int argc, char const *argv[]) {
 
    Stack mystk;
 
    mystk.push(3);
    mystk.push(4);
    mystk.push(221);
    mystk.push(43);
    mystk.push(60);
    mystk.push(10);
    mystk.push(345);
    mystk.push(78);
    mystk.push(40);
    mystk.push(890);
 
    mystk.print();
    cout << "pushed 10" << endl;
 
    mystk.push(2019);
    mystk.push(22203);
    mystk.print();
 
    return 0;
}