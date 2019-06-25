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

    string s;
    cin>>s;

    bool **isPal;
    int **dp;

    int n = s.size();
    dp = new int*[n+1]; 
    isPal = new bool*[n+1];
    for(int i=0; i<=n; i++)
    {    dp[i] = new int[n+1]; isPal[i]=new bool[n+1];       }
    
    for(int i=0; i<=n; i++){    
        for(int j=0; j<=n; j++)
        {    dp[i][j]=0;isPal[i][j]=0;     }
    }

    for(int i=0; i<=n; i++)
    {    dp[i][i]=1; isPal[i][i]=1;  }

    for(int start = 0; start<n-1; start++){
        for(int len = start+1; len<n-start; len++){
            isPal[start][start+len-1] =  isPal[start+1][start+len-2] & (s[start] == s[start+len-1]);
        }
    }

    for(int start = 0; start<n-1; start++){
        for(int len = start+1; len<n-start; len++){
            dp[start][start+len-1] = dp[start][start+len-2] + dp[start+1][start+len-1] - dp[start+1][start+len-2] + isPal[start][start+len-1];
        }
    }

    int q,l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<dp[l][r]<<"\n";
    }
    for(int i=0; i<=n; i++){    delete[] dp[i]; delete[] isPal[i];       }
    delete[] dp; delete[] isPal;
    return 0;
}
