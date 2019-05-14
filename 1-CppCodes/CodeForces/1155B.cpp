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

    int n,b,c;
    string s;
    cin>>n>>s;

    b = n-11; c = 0;
    for(int i=0; i<=b; i++){
        if(s[i]=='8'){  c++;    }
    }

    if(c>(b>>1)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

    return 0;
}
