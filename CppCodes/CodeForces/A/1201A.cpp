/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
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

    int n,m;
    cin>>n>>m;

    string s[1000+1];
    int a[1000+1]={0};
    for(int i=0; i<n; i++){    cin>>s[i];  }

    for(int i=0; i<m; i++){ cin>>a[i];  }


    int ans = 0;

    for(int i=0; i<m; i++){
        int ch[27]={0};
        for(int j=0; j<n; j++){
            int c = s[j][i]-'A';
            ch[c]++;
        }
        int maximus = 0;
        for(int i=0; i<26; i++){    maximus = max(maximus, ch[i]);  }
        ans += maximus*a[i];
    }

    cout<<ans<<"\n";

    return 0;
}