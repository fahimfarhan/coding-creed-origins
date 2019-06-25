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

    int n,x, y;
    cin>>n>>x;
    int *pos, *neg;

    pos = new int[x+1];
    neg = new int[x+1];

    for(int i=0; i<=x; i++){    pos[i] = 0; neg[i]=0; }
    for(int i=0; i<n; i++){
        cin>>y;
        if(y<0){
            y=-y;
            neg[y]++;
        }else{
            pos[y]++;
        }
    }

    int res=0;
    res+=pos[0];
    for(int i=1; i<=x; i++){
        res+=abs(pos[i]-neg[i]);
    }

    cout<<res<<"\n";
    
    delete[] pos;
    delete[] neg;

    return 0;
}
