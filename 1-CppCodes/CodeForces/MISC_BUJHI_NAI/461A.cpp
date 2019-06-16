#include<bits/stdc++.h>
using namespace std;
long long n,arr[1000001],s,i;
main()
{
    cin>>n;
    for(i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    s+=(i+2)*arr[i];
    cout<<s-arr[n-1];
}