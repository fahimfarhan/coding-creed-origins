/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

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

    ll n,k;

    cin>>n>>k;
    ll a[n+2] = {INT_MAX};

    for(int i=0; i<n; i++){ cin>>a[i];  }

    sort(a,a+n);

    int midPoint = n/2;

    ll ans = 0;
    int j=midPoint+1;

    while(true){
        while( (a[j]==a[midPoint]) && (j<=n) ){  j++;   }
        {
            ll nextVal = a[j+1];
            ll h = nextVal - a[midPoint];
            ll d = j-midPoint;
            ll h1 = h*d;
            if(h1<=k){
                a[midPoint]+=d;
                k-=h1;
                if(k==0){   break; }
            }else{
                h = k/d;
                a[midPoint]+=h;
                break;
            }
        }
    }

    if(k>0){
        ll h = a[n-1]-a[midPoint];
        ll d = n-1-midPoint;

        if(k>=d){
            k = k/d;
            a[midPoint]+=k;
        }
    }

    cout<<a[midPoint]<<"\n";    

    

    return 0;
}