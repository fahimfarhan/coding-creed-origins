#include<iostream>
#include<algorithm>
using namespace std;

int check(int *a, int n){
    if(n==1) return 1;
    else if(is_sorted(a,a+n)) return n;
    else return max(check(a,n/2),check(a+n/2,n/2));
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<check(a,n)<<endl;
    return 0;
}