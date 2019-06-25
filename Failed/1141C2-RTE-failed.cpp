#include <bits/stdc++.h>

using namespace std;

int main()
{
    int *p,*used;
    int q, n, minimus;
    minimus = 0; 

    cin>>n;
    p=new int[200010]; used = new int[200010];
    p[0]=0;

    for(int i=0; i<n-1;i++ ){
        cin>>q; p[i+1]=p[i]+q;
        if(p[i+1]<p[minimus]){ minimus = i+1;  }
    }

    int x = 1 - p[minimus];

    for(int i=0; i<n; i++){ 
        p[i] = p[i]+x;
        used[p[i]]++;
        if( (p[i]<1) || (p[i]>n) || (used[p[i]]>1) ){   cout<<"-1\n"; return 0; }
    }
    for(int i=0; i<n; i++){ cout<<p[i]<<" ";   }
    
    cout<<"\n";

    if(!p)delete[] p;
    if(!used)delete[] used;
    return 0;
}