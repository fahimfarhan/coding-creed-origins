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

    map<char, int> mp1,mp2;
    string s;
    int n;
    cin>>n;
    for(int i=0;i<n; i++)
    {
        cin>>s;
        if( mp1[s[0]] <= mp2[s[0]] ){
            mp1[s[0]]++;
        }else{
            mp2[s[0]]++;
        }
    }

    map<char, int>:: iterator it;
    ll maximus = 0;
    int m;
    for(it = mp1.begin(); it!=mp1.end(); it++){
        m = it->second;
        n = m*(m-1);
        n = n>>1;
        maximus+=n;

    }

    for(it = mp2.begin(); it!=mp2.end(); it++){
        m = it->second;
        n = m*(m-1);
        n = n>>1;
        maximus+=n;

    }
    
    
    cout<<maximus<<"\n";

    return 0;
}
