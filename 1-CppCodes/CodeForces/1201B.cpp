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

    ll n=0, a=0,one=1, maximus=0, sum=0;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        maximus = max(maximus,a);
        sum+=a;
    }

    if( ((sum&one) == 0) && (maximus<=(sum-maximus))){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}