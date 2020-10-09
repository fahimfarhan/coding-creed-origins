#include <bits/stdc++.h>

using namespace std;

int main(){
    int count=0;
    for(int i=1; i<10000; i++){
        for(int j=i; j<10000; j++){
            if(i*j == i+j){
                count++;
                cout<<i<<" "<<j<<"\n";
            }
        }
    }
    cout<<count<<"\n";
    return 0;
}