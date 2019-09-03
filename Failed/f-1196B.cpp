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

    ll q, n, k, temp,s, one = 1;
    vector<ll> v;
    cin>>q;
    while(q--){
        if(!v.empty()){ v.clear();  }
        cin>>n>>k;
        ll a[n];
        for(int i=0; i<n; i++){ cin>>a[i];  }
        s = 0;
        int i=0;
        for(i=0; i<n; i++){
            s+=a[i]; 
            ll k1 = k-1;
            if( (s&one) == one){    v.push_back(i); k1--; s = 0; }
        }
        s = 0;
        int j=0;
        for(j=i; j<n; j++){ s+=a[i]; }
        if( (s&one) == one){   v.push_back(j); }

        if(v.size() == k ){
            cout<<"YES\n";  
            for(int i=0; i<k; i++){
                cout<<(v[i]+1)<<" ";
            }cout<<"\n";
        }else{
            cout<<"NO\n";
        }
    
    }


    return 0;
}