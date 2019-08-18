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

    ll n, N;
    cin>>n;
    if(n%2 == 0){
        cout<<"NO\n"; exit(0);
    }

    cout<<"YES\n";
    N = n<<1;

    ll a[N+1];
    ll next=0;

    ll j=1;
    for(int i=0; i<N; i++){
        if(next>=N){    next=next%N; }
        a[next] = j;
        j++;
        if( (i&1) == 0){
            next+=n;
        }else{
            next-=1;
        }
    }

    for(int i=0; i<N; i++){
        cout<<a[i]<<" ";
    }cout<<"\n";


    return 0;
}