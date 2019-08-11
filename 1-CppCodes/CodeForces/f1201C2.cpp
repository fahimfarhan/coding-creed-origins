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

    ll a[n+10] = {INT_MAX};

    for(int i=0; i<n; i++){ cin>>a[i];   }    

    sort(a,a+n);

    int mid = n/2;
    int j=mid+1;

    while(a[j]!=INT_MAX ){
        if(j>=n){   break;  }
        while(true){    j++; if(a[j]>a[mid]){break;} if(j>=n){   break;  }    }
        ll h = a[j]-a[mid];
        ll d = j-mid;

        ll k1 = k/d;
        if(k1==0 || h==0){  k1 = max(k1, h);    }
        else{ k1 = min(k1, h); }
        k-=k1;
        a[mid]+=k1;
        if(k<=0){   break;  }
    }

    cout<<a[mid]<<"\n";

    return 0;
}