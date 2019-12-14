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

    int T, n;
    ll a, x, one = 1, kount = 0;
    set<ll> s;

    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0; i<n; i++){ 
            cin>>a;
            if( !(a&one) ){
                s.insert(a);
            }
        }
        kount = 0;
        while(s.size()>0){
            set<ll>::reverse_iterator it = s.rbegin();
            x = *it;
            s.erase(x);
            x = x>>1;
            if( !(x&one) )s.insert(x);
            kount++;
        }

        cout<<kount<<"\n";
    }


    return 0;
}

