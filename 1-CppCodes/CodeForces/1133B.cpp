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

    int n,k;
    ll d;
    int *cnt;

    cin>>n>>k;
    cnt = new int[k+1];
    for(int i=0; i<=k; i++){    cnt[i] = 0; }

    for(int i=0; i<n; i++){
        cin>>d;
        d = d%k;
        cnt[d]++;
    }

    ll result = 0;
    
    result+=((cnt[0]>>1)<<1);

    if(k==2){
        result+=((cnt[1]>>1)<<1);
    }else{
        int mid = (k-1)>>1;
        int minimus;
        for(int i=1; i<=mid; i++){
            minimus = min(cnt[i], cnt[k-i]);
            minimus = minimus<<1;
            result+=minimus;
        }

        if( (k&1) != 1 ){
            mid = k>>1;
            result+=((cnt[mid]>>1)<<1);
        }
    }

    cout<<result<<"\n";

    delete[] cnt;

    return 0;
}
