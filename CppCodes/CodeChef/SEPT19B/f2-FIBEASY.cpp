/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;
#define SIZE 10000007
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

ll T,N;
vector<short> v;

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

    // preprocessing
    v.push_back(0);v.push_back(0); v.push_back(1);

    int a=0, b=1, c = 0;
    ll next = 4;
    for(ll i=3; i<SIZE; i++){
        c = b+a;
        if(c>=10){  c-=10;  }
        a = b;
        b = c;
        if(i==next){    v.push_back(c); next = next<<1; }

    }

    for(int i=0; i<10; i++){    cout<<v[i]<<" ";   }cout<<"\n";

    // main task
    cin>>T;
    ll r = 0;
    while(T--){
        cin>>N;
        r = log2(N);
        cout<<v[r]<<"\n";
    }

    return 0;
}