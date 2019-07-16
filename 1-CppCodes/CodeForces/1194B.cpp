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

ll q, n, m, rmax, cmax, ans;
char ch;

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


    cin>>q;
    while(q--){
        ll row[50000] = {0};
        ll col[50000] = {0};
        rmax = 0; cmax = 0;
        cin>>n>>m;

        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>ch;
                if(ch == '*'){
                    row[i]++; col[j]++;
                    rmax = max(rmax, row[i]);
                    cmax = max(cmax, col[j]);
                }
            }
        }

        ans = (n - rmax) + (m - cmax);

        cout<<ans<<"\n";
    
    }
    return 0;
}