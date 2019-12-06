#include <bits/stdc++.h>

using namespace std;

#define N 9
int a[N] = {10,22,9,33,21,50,41,60,80};

int lis[N] = {0};
int maximus = 0;

int main(){

    // base case i = 0 => l(0) = 1
    lis[0] = 1;
    for(int i=1; i<9; i++){
        maximus = 0;
        for(int j=0; j<i; j++){
            if(a[j]<a[i]){  maximus = max(maximus, lis[j]); }
        }
        lis[i] = 1 + maximus;
    }
    cout<<lis[N-1]<<"\n";
    return 0;
}