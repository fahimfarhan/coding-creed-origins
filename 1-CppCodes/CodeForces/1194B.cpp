#include <bits/stdc++.h>
 
using namespace std;
 
#define PI 2*acos(0)
 
typedef int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
// ll MODULO = 1e9+7;
 
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);
 
 
// int n,m;s
vector<int> *g;
bool *isvisited;
 
ll q, n, m, rmax, cmax, ans, r_index, c_index;
 
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
        //ll row[50000] = {0};
        //ll col[50000] = {0};
        rmax = 0; cmax = 0;
        cin>>n>>m;
        ll row[n+1]={0};
        ll col[m+1]={0};
        bool a[n+1][m+1];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>ch;
                if(ch == '.'){
                    a[i][j] = 1;
                    row[i]++; col[j]++;
                   
                }else{  a[i][j] = 0; }
            }
        }
 
        ans=INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ll temp = row[i]+col[j]-(ll)a[i][j];
                if(temp<0){ temp = INT_MAX; }
                ans = min(ans, temp);
            }
        }
        cout<<ans<<"\n";
    
    }
    return 0;
}