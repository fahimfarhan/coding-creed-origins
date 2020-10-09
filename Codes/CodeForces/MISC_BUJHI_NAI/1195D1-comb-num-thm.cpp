#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 998244353;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int add(int a, int b){
    int ret=0;
    ret = a+b;
    if(ret >=MODULO){    ret-= MODULO; }
    if(ret<0){    ret+=MODULO;  }
    return ret;
}

int mul(int a, int  b){
    return (int)((a*(b*1ll))%MODULO);
    
}

int len;
vector<int> pw10;

int f(int a){
    int pos = 0;
    int res = 0;

    while(a>0){
        int curr = a%10;
        a/=10;
        int l = pos<<1; int r = l|1;
        res = add(res, mul(curr, pw10[l]));
        res = add(res, mul(curr, pw10[r]));
        pos++;
    }
    return res;
}

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

    pw10 = vector<int>(30);
    pw10[0] = 1;
    for(int i=1; i<30; i++){
        pw10[i] = mul(10, pw10[i-1]);
    }

    int n;
    cin>>n;
    int ans = 0;

    
    for(int i=0; i<n; i++){
        int a=0;
        cin>>a;
        len = to_string(a).size();
        ans = add(ans, mul(n,f(a)));
    }

    cout<<ans<<"\n";

    return 0;
}