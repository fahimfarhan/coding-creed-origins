#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

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
    int ans,n,x,y;
    string s,t;
    cin>>n>>x>>y;

    cin>>s;
    reverse(s.begin(), s.end());
    t = s;
    ans = 0;
    for(int i=0; i<y; i++){
        t[i] = '0'; 
        if(s[i]!=t[i]){
            ans++;
        }
    }

    t[y] = '1';
    if(s[y]!=t[y]){ ans++; }

    for(int i = y+1; i<x; i++){
        t[i] = '0'; 
        if(s[i]!=t[i]){ ans++; }
    }
    t[x] = '1';
    if(s[x]!=t[x]){ ans++; }

    // cout<<s<<"\n"<<t<<"\n";

    cout<<(ans)<<"\n";


    return 0;
}
