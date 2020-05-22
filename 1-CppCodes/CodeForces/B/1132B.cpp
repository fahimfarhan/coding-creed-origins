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
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    int *a, *b;
    int minimus;

    cin>>n;
    a = new int[n+1];
    for(int i=0; i<n; i++){ cin>>a[i]; }
    cin>>q;
    b = new int[q+1];
    //minimus = INT_MAX;
    for(int i=0; i<q; i++){ cin>>b[i];   }

    sort(a,a+n);
    ll sum=0;
    for(int i=0; i<n; i++){     sum+=a[i];     }
    
    ll ans=0;
    for(int i=0; i<q; i++){
        ans = sum-a[n-b[i]];
        cout<<ans<<"\n";
    }
    
    

    delete[] a;
    delete[] b;
    return 0;
}
