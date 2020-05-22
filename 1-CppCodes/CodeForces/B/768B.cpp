#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

ll L,R;

ll divideAndConcure(ll n, ll l, ll r){
    if( (n==0)||(r<L)||(l>R) ){    return 0;   }
    if(n == 1){ return 1; }
    else{
        ll first_last = n>>1; // n=n/2 
        ll mid = ((l+r)>>1); // (l+r) / 2
        ll M = (n&1);
        ll ret = 0;
        ret = divideAndConcure(first_last, l,mid-1) + divideAndConcure(M,mid,mid) + divideAndConcure(first_last, mid+1, r);
        return ret;
    }
    return 0;
}

ll getLen(ll m){
    ll len = 1;
    ll a = m;
    while(a>1){
        a=(a>>1); // a=a/2 
        len = ((len<<1) | 1);
    }
    return len;
    /*
    //if(m==0){   return 0;   }
    if(m<=1){   return 1;   }
    m = m>>1; // m=m/2 
    m = getLen(m);
    m = (m<<1)+1; // m = 2m+1
    return m;*/
}

int main(int argc, char const *argv[])
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

    ll n;
    cin>>n>>L>>R;

    // step 1: find final array size! 
    ll len = getLen(n);

    ll ans = divideAndConcure(n,1,len);

    cout<<ans<<"\n";
    
    return 0;
}
