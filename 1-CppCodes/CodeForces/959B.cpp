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

    int n,k,m;
    map<string, int > mp;
    string *s;
    cin>>n>>k>>m;
    s = new string[n+1];
    for(int i=1; i<=n; i++){cin>>s[i]; }

    int cost,x;
    for(int i=1; i<=n; i++){cin>>x; mp[s[i]]=x; }

    int l,p,minimus;
    int *b;
    for(int i=0; i<k; i++){
        cin>>l;
        b = new int[l+1];
        minimus = INT_MAX;
        for(int j=0; j<l; j++){
            cin>>b[j]; minimus  = min( mp[s[b[j]]],minimus);
        }
        for(int j=0; j<l; j++){
            mp[s[b[j]]] = minimus;
        }
        delete[] b;
    }

    int ans = 0;
    string t;
    for(int i=0; i<m; i++){ cin>>t; ans+=mp[t]; }

    cout<<ans<<"\n";
    delete[] s;
    return 0;
}
