#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef int64_t ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
//vector<int> *g;
bool *isvisited;


int T;
ll l,r,g, s;
ll lb, ub;

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

    cin>>T;
    while(T--){
        cin>>l>>r>>g;
        lb = l/g;
        if((l%g)!=0){ lb++; }
        lb = lb*g;
        
        ub = r/g;
        ub = ub*g;

        if(g>r){    s = 0;  }
        else if(lb>ub){  s = 0; }
        else{
            s = 1+(ub-lb)/g;
        }

        cout<<s<<"\n";

    }

    return 0;
}
