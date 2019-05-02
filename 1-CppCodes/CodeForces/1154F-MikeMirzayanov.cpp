#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

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

    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n);
    for(int i=0; i<n; i++){ cin>>a[i];  }

    sort(a.begin(), a.end());
    a.resize(k);
    reverse(a.begin(), a.end());

    vector<int> offers(k+1);

    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        if(x<=k){
            offers[x] = max(offers[x],y);
        }
    }

    vector<int> pref(k+1);
    for (int i = 0; i < k; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}

    vector<int> dp(k+1, INT_MAX);
    dp[0]=0;

    for(int i=0; i<k; i++){
        dp[i+1] = min(dp[i+1], dp[i]+a[i]);
        for(int j=1; j<=k; j++){
            if(offers[j]==0){  continue;   }
            if(i+j>k){break;}
            dp[i+j] = min( dp[i+1], dp[i]+pref[i+j-offers[j]]-pref[j]);
        }
    }

    cout<<dp[k]<<"\n";


    return 0;
}
