#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

    int n, *a;

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

    cin>>n;
    a = new int[n+1];
    for(int i=0; i<=n; i++){    a[i] = 0; }
    
    
    int u = 1;
    for(int i=2; i<=n; i++){
        if(a[i]==0){
            a[i] = u;
            u++;
            for(int j=i+i; j<=n; j+=i){
                a[j] = a[i];
            }
        }
    }

    for(int i=2; i<=n; i++){    cout<<a[i]<<" ";    }
    cout<<"\n";

    delete[] a;

    return 0;
}
