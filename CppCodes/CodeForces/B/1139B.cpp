#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
    /* Soln soln */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; ll *a;
    cin>>n;
    a = new ll[n+1];
    for(int i=0; i<n; i++){ cin>>a[i]; }

    ll ans = a[n-1];
    int start = n-2;

    ll minimus;
    for(int i=start; i>=0; i--){
        minimus = min(a[i], a[i+1]);
        if(minimus==a[i+1]){    minimus--; }
        if(minimus <0){ minimus = 0; break;  }


        a[i] = minimus;
        ans+=minimus;
    }
    cout<<ans<<"\n";

    delete[] a;
    return 0;
}