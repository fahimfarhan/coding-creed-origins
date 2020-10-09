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

ll T, Q, X;

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
        int m, a[2]={0};
        
        set<int> s;
        cin>>Q;
        for(int i=0; i<Q; i++){
            cin>>X;
            s.insert(X);
            a[0] = 0; a[1] = 0;
            for(set<int>::iterator it=s.begin(); it!=s.end(); it++){
                m = (*it);
                m = __builtin_popcount(m);
                a[(m%2)]++;
            }
            cout<<a[0]<<" "<<a[1]<<"\n";
        }
    }

    return 0;
}