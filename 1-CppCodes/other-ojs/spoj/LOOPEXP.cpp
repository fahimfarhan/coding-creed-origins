#include <bits/stdc++.h>

using namespace std;

int main(){
    cout << setprecision(8);
    
    int T, n;
    double *a = new double[100001];

    a[1] = 1; // xp = x.1/i =  1.(1/1)
    for(int i=2; i<100001; i++){
        a[i] = a[i-1]+1.0/i;
    }

    cin>>T;


    while(T--){
        cin>>n;
        cout<<a[n]<<"\n";
    }
    if(!a)delete[] a;
    return 0;
}