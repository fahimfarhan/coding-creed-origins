#include <bits/stdc++.h>

#define ll long long int

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    double mean, median, mode;
    ll *a;
    cin>>n;

    a = new ll[n+1];

    for(int i=0; i<n; i++){     cin>>a[i];    }
    sort(a,a+n);
    // mean 
    mean = 0;
    for(int i=0; i<n; i++){ mean+=a[i]; }
    mean = mean*1.0;
    mean=mean/n;

    cout<<mean<<"\n";

    // median
    int m = n/2; // 10/2 = 5 , 11/2 = 5  
    if(n%2==0){
         
        median = (1.0*(a[m]+a[m-1]))/2;
    }else{
        median = a[m];
    }

    cout<<median<<"\n";

    // mode 
    map<int, int> mp;
    for(int i=0; i<n; i++){ mp[a[i]]++; }
    
    mode = a[0];
    int maximus = mp[a[0]];

    for(int i=01; i<n; i++){ 
        if(mp[a[i]]> maximus){  mode = a[i]; maximus = mp[a[i]];    }
   }

    cout<<mode<<"\n";

    if(!a)delete[] a;
    return 0;
}

