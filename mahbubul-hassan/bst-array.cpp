/**
 * FAILED SEGMENTATION FAULT
 * 
*/
#include <bits/stdc++.h>
using namespace std;

int SIZE = 1;
int *g;

void increaseSize(){
    int oldSize = SIZE;
    SIZE = SIZE<<1;
    int *temp = new int[SIZE+1];
    for(int i=oldSize; i<SIZE; i++){  temp[i] = INT_MIN; }
    for(int i=0; i<oldSize; i++){    temp[i] = g[i];     }
    if(g!=NULL)delete[] g;
    g = temp;
    temp = NULL;
}

void insert(const int& m){
    if(g == NULL){
        g = new int[SIZE+1];
        g[1] = m;
    }else{
        int index = 1;
        while(g[index]!=INT_MIN){
            if(m <= g[index]){
                index = index<<1;
                if(index >= SIZE){  
                    increaseSize(); 
                }
            }else if(m > g[index]){
                index = (index<<1)|1;
                if(index >= SIZE){  
                    increaseSize(); 
                }
            }
        }
        g[index] = m;
    }
}

int search(const int& x){
    int ret = 1;
    while(true){
        if( ret >= SIZE ){ return -1;  }
        if( g[ret] == x ){  return x;  }
        else if(x < g[ret]){    ret = ret<<1; }
        else if(x > g[ret]){    ret = (ret<<1)|1;   }
    }
}


bool Delete(const int& x){
    bool isDeleted = false;
    int pos = search(x);
    if(pos == -1){  return isDeleted; }
    else{
        isDeleted = true;
        g[pos] = INT_MIN;
        int index = (pos<<1)|1;
        if(index < SIZE){
            int inOrderSuccessor = INT_MIN;
            while( (index<SIZE) && (g[index]!=INT_MIN) ){
                inOrderSuccessor = g[index];
                index = (index<<1);
            }
            g[pos] = inOrderSuccessor;
        }
    }

    return isDeleted;
}

void update(const int& old, const int& value){
    int pos = search(old);
    int left, right;
    if(pos != -1){
        g[pos] = value;
        while(true){
            left = pos << 1;
            right = left | 1;
            if( (left < SIZE) && (g[pos] < g[left]) ){
                swap(g[pos], g[left]);
                pos = left;
            }else if( (right < SIZE) && (g[pos] > g[right]) ){
                swap(g[pos], g[right]);
                pos = right;
            }else{
                break;
            }
        }
    }
}

void printer(){
    for(int i=0; i<SIZE; i++){
        if(g[i]==INT_MIN){ cout<<"x "; }
        else { cout<<g[i]<<" "; }
    }cout<<"\n";
}

void basicBstDemo(){
char ch;
    int n;
    while(true){
        cin>>ch;
        if(ch == 'I' || ch =='i'){
            cin>>n;
            insert(n);
            printer();
        }else if(ch == 'D' || ch == 'd'){
            cin>>n;
            if(Delete(n)){
                cout<<n<<" deleted\n";
                printer();
            }else{
                cout<<n<<" is not deleted\n";
            }
        }else if(ch == 's' || ch == 'S'){
            cin>>n;
            cout<<search(n)<<"\n";
        }else if(ch =='p' || ch == 'P'){
            printer();
        }else if(ch == 'u' || ch == 'U'){
            int m;
            cin>>n>>m;
            update(n,m);
            printer();
        }
        else if(ch =='X' || ch=='x'){ break;  }
    }
}

void myDestructor(){
    if(g!=NULL) delete[] g;
}


int main(){
    basicBstDemo();
    myDestructor();

    return 0;
}
