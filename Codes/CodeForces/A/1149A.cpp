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

    int n,x;
    int cnt[3] = {0};

    cin>>n;
    for(int i=0; i<n; i++){ cin>>x; cnt[x]++; }

    if(cnt[2]){ cout<<"2 "; cnt[2]--; }
    if(cnt[1]){ cout<<"1 "; cnt[1]--; }

    while(cnt[2]){ cout<<"2 "; cnt[2]--; }
    while(cnt[1]){ cout<<"1 "; cnt[1]--; }
    cout<<"\n";

    return 0;
}
