#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n+1] = {0};
    for(int i=1; i<=n; i++){    cin>>a[i];  }

    for(int i=1; i<=n; i++){
        if( (a[i]==3) && (a[i]!=a[i-1]) ){
            a[i] = a[i] - a[i-1];
        }
        if(a[i]==a[i-1] && a[i]!=3){
            a[i] = 0;
        }
    }
    int kount = 0;
    for(int i=1; i<=n; i++){   if(a[i] == 0) kount++;    }

    cout<<kount<<"\n";

    return 0;
}