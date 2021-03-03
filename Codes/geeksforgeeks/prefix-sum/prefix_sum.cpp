#include <bits/stdc++.h>

using namespace std;

int main(){
    int input[] = {1,2,3,4,5,6,7,8,9};
    int output[]= {0,0,0,0,0,0,0,0,0};

    int sum = 0;
    for(int i=0; i<9; i++){
        sum = sum+input[i];
        output[i] = sum;
    }
    for(int i=0; i<9; i++){     cout<<output[i]<<" ";   }
    return 0;
}