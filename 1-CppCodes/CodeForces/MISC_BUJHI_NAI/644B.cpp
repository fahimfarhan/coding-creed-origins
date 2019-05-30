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
queue<ll> q;
int n,b;
ll *a;
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
    cin>>n>>b;
    a = new ll[n+1];

    int t,d;
    for(int i=0; i<n; i++){
        cin>>t>>d;
        while(!q.empty() && q.front()<=t){  q.pop(); }
        if(q.size()>b){ a[i]=-1; }
        else if(q.empty()){ a[i] = t+d; q.push(a[i]); }
        else{
            a[i] = q.back()+d;
            q.push(a[i]);
        }
    }

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<"\n";

    delete[] a;
    return 0;
}
