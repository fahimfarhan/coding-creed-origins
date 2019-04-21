#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,k,A,B,*a;

ll divideAndConquire(int l,int r)
{
  ll mid=(l+r)>>1; 
  ll na=upper_bound(a,a+k,r)-lower_bound(a,a+k,l);
  if(na==0)return A;
  if(l==r)return B*na;
  return min(na*B*(r-l+1),divideAndConquire(l,mid)+divideAndConquire(mid+1,r));
}

int main()
{
     /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>k>>A>>B;
    a = new ll[k+1];
    
    for(ll i=0;i<k;i++){  cin>>a[i];  }
    sort(a,a+k);
    n = (1ll<<n);
    cout<<divideAndConquire(1,n)<<endl;

    return 0;

}