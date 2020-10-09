/**
 * @brief: soln credit thanks to saiful.dh
 *  @link: https://codeforces.com/problemset/submission/1389/88334647
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100009],b[100009],c;
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i]+(i?b[i-1]:0);
    }
    c=b[m];
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=m-2*i;j++)
            c=max(c,(a[j]+a[j+1])*i+b[m-2*i]);
    }
    cout<<c<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)sol();
}