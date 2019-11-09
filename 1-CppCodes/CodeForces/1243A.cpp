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

    ll t, n, m, h, w, *a;
    cin>>t;
    while(t--){
        cin>>n;
        a = new ll[n+1];
        
        for(int i=0; i<n; i++){     cin>>a[i];  }
        
        sort(a,a+n);
        m = INT_MIN;
        for(int i=0; i<n; i++){
            h = a[i];
            w = n-i;
            // if(h<=w){   m = min(h,w);   }
            // else{   break;  }
            ll temp = min(h,w);
            m = max(m,temp);
        }

        cout<<m<<"\n";
        delete[] a;
    }


    return 0;
}

