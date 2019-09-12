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

    ll T;
    cin>>T;

    ll n,x,d,h, minimus, curr, result, hmax, dmax;
    while(T--){
        cin>>n>>x;
        minimus = INT_MAX;
        for(int i=0; i<n; i++){
            cin>>d>>h;
            
            ll a = x-d;
            ll d1=d-h;

            ll n = (d1+a)/d1;

            if(a-(n-2)*d1<=0){ result = n-1;   }
            else if(a-(n-1)*d1<=0){  result = n; }

            minimus = min(minimus, result);
        }
        cout<<minimus<<"\n";


        // cout<<result<<"\n";
    }


    return 0;
}