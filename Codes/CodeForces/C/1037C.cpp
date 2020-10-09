#include <bits/stdc++.h>

using namespace std;

int main(){
    int kount,i,n;
    string a,b;
    cin>>n;
    cin>>a;
    cin>>b;


    i=0, kount=0;
    while(i<n){
        if(a[i]!=b[i]){
            if( (i+1<n) && (a[i+1]!=b[i+1]) && (a[i]!=a[i+1])){
                kount++;
                i+=2;
            }else{
                kount++;
                i++;
            }
        }else{
            i++;
        }
    }

    cout<<kount<<"\n";
    return 0;
}