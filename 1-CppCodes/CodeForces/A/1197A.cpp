#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll int
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

    ll T, n, k,res, *a;

    cin>>T;
    while(T--){
        cin>>n;
        a = new ll[n+1];

        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        res = 0;
        if(n<3){    res = 0;    }
        else{
            
            res = min(min(a[n-1], a[n-2])-1, n-2);
            
        }
        cout<<res<<"\n";

        if(!a)delete[] a;
    }


    return 0;
}