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

    ll n;
    cin>>n;
    ll a[n+1] = {0};
    short b[1000000000] = {0};

    for(int i=0; i<n; i++){ cin>>a[i];  }

    int l = 0;
    ll llval = 0;

    while(l<n){
        int temp = a[l];
        if(b[temp]==0){
            b[temp] = 1;
        }else{
            llval = temp;
            break;
        }
    }

    if(l==n){   cout<<0<<"\n";  }

    int  r = n-1;
    while(r>=0){
        int temp = a[r];
        if(b[temp] == 1 ){   b[temp] = 1; }
        else{   break; }
    }

    cout<<r-l+1;


    return 0;
}