#include <bits/stdc++.h>
    
using namespace std;
    
    
int main(int argc, char const *argv[])
{
    /* code */
    int64_t n,m;
    //scanf("%d",&n);
    cin>>n;
    if((n&1)==1){ // that is, n%2==1
        m = -(n+1)/2;
    }else{
        m = n/2;
    }
    
    //printf("%d\n",m);
    cout<<m<<"\n";
    return 0;
}