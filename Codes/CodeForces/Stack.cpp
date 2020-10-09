#include <bits/stdc++.h>

using namespace std;

class Stack{
private:
    int curr, SIZE, *stck, *temp;
public:
    Stack(){
        curr = -1;
        SIZE = 1;
        stck = new int[SIZE+1];
    }

    int size(){ return (curr+1); }

    void push(int& input){
        if(curr == SIZE){
            temp = new int[SIZE+1];
            for(int i=0; i<SIZE; i++){  temp[i] = stck[i];  }

            delete[] stck;
            SIZE = SIZE<<1;
            stck = new int[SIZE+1];
            for(int i=0; i<curr; i++){  stck[i] = temp[i];  }
            cout<<"Stack resized successfully! New size = "<<SIZE<<"\n";
        }

        stck[curr] = input;
        curr++;
    }

    void pop(){    stck[curr]=0; curr--;     }
    
    bool isEmpty(){  
        if(curr = -1){  return true; }
        else{ return false;   }  
    }

    int top(){   
        if(curr!=-1)return stck[curr];
        else return 0;   
    }

    ~Stack(){     if(!stck) delete[] stck;   }
};

int main(){
    Stack s;
    int m;
    for(int i=0; i<100; i++){    s.push(i);  }
    for(int i=0; i<100; i++){    m=s.top(); s.pop(); cout<<m<<"\n";  }

    return 0;
}