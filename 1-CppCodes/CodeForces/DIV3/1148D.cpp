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

    int n,a,b;
    vector< pair<int,int> > v1,v2,v;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        if(a<b){    v1.push_back({(n-1)-a,i});    }
        else{   v2.push_back({a,i});     }
    }

    if(v1.size() > v2.size() ){ v = v1; }
    else{   v = v2; }

    sort(v.begin(), v.end());

    cout<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++)
    {  cout<<(v[i].second+1)<<" ";  }cout<<"\n";
    
    return 0;
}
