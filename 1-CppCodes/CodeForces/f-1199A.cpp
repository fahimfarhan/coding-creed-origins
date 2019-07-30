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

    ll n,d, x,y,res;
    cin>>n>>x>>y;

    ll a[n+20];
    for(int i=0; i<n+20; i++){  a[i] = INT_MAX; }
    
    for(int i=10; i<=n+10; i++){    cin>>a[i];  }

    res = 0;
    d = 0;
    bool b = true, b1 = false;
    
    for(int i=x+1+10; i<=n+10; i++){
        d = i;
        bool b = true;
        for(int j=d-x; j<=d+y; j++){
            
            if(d==j){   continue; }
            else{
                if(a[d]>a[j]){ b = false; break; }
            }
        }
        if(b){  res = i; break;     }
    }

    cout<<res-10<<"\n";
    //delete[] a;
    return 0;
}