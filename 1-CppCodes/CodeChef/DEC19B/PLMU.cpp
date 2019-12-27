#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    long long int N, a, zeroCount, twoCount, two = 2, zero = 0;

    cin>>T;
    while(T--){
        cin>>N;
        zeroCount = 0; twoCount = 0;
        for(int i=0; i<N; i++){
            cin>>a;
            if(a == two){   twoCount++; }
            else if(a == zero){ zeroCount++;    }
        }

        a = zeroCount*(zeroCount-1)/2 + twoCount*(twoCount-1)/2;
        cout<<a<<"\n";
    }

    return 0;
}