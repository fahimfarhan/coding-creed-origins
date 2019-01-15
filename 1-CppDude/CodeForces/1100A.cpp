
#include <bits/stdc++.h>

using namespace std;

int
main ()
{
    ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 int d,n,k,maximus,bb,e,s, *a;
 maximus = INT_MIN;
 bool *b;
 cin>>n>>k;
 a = new int[n+1];
 
 //for(int i=0; i<=n; i++){   b[i] = true; }
 for(int i=1; i<=n; i++){   cin>>a[i]; }
 
 for(int i=1; i<=k; i++){
    b = new bool[n+1];
    //bool b[n+1];
    //memset(b,true, sizeof(b));
    for(int j=0; j<=n; j++){    b[j] = true; }
    for(int j=i; j<=n; j+=k){
        b[j] = false;
    }
    e=0; s=0;
    for(int j=1; j<=n; j++){    
        if(b[j]){
            if(a[j] == 1){  e++; }
            else{   s++; }
        }
    }
    d = abs(e-s);
    maximus = max(maximus, d);
    
    delete[] b;
    
 }
 
 cout<<maximus<<"\n";
 
 delete[] a;
 
  return 0;
}