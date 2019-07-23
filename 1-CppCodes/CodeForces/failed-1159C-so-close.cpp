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
// vector<int> *g;
bool *isvisited;

int n,m;
int *g, *b;
ll ans = 0;
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

    cin>>n>>m;
    b = new int[n+1]; g = new int[m+1]; 

    for(int i=0; i<n; i++){ cin>>b[i];  }
    for(int i=0; i<m; i++){ cin>>g[i];  }
    
    sort(b,b+n); sort(g,g+m);
    if(b[n-1]>g[m-1]){
        cout<<"-1\n";
    }else{
        ans = 0;
        bool b123 = true;
        for(int i=0; i<n; i++){ ans+=m*b[i]; }
        int j=n-1, mcount = m-1;

        for(int i=m-1; i>=0; i--){
            ans=ans-b[j]+g[i];
            mcount--;
            if(mcount==0){
                mcount=m-1;
                j--;
                if(j<0){
                    // another impossible i guess 
                    b123 = false; break;
                }
            }
        }
        if(b123){   cout<<ans<<"\n";    }
        else{   cout<<"-1\n";   }
    }
    delete[] b; delete[] g;
    return 0;
}
