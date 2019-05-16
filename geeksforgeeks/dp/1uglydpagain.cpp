#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, *a;

    cin>>n;
    a = new int[n+1];

    a[0] = 1; 
    int i2=0, i3 = 0, i5 = 0;
    int next_multiple_of_2=2,next_multiple_of_3=3,next_multiple_of_5=5; 
    int next_ugly_num = 0;

    for(int i=1; i<n; i++){
        next_ugly_num = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));

        a[i] = next_ugly_num;
        cout<<a[i]<<" ";
        if(next_ugly_num == next_multiple_of_2){
            i2=i2+1;
            next_multiple_of_2 = a[i2]*2;
        }
        if(next_ugly_num == next_multiple_of_3){
            i3=i3+1;
            next_multiple_of_3 = a[i3]*3;
        }
        if(next_ugly_num == next_multiple_of_5){
            i5=i5+1;
            next_multiple_of_5 = a[i5]*5;
        }
    }cout<<"\n";
    
    delete[] a;
    return 0;
}