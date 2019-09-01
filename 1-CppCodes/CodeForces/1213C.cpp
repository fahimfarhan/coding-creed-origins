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

    ll a[15][15];
    ll cf[15][15];

    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){    a[i][j] = 0; cf[i][j] = 0;   }
    }
    
    for(int i=1; i<=10; i++){
        int temp = i;
        for(int j=1; j<=10; j++){
            a[i][j] = (temp%10);
            temp+=i;
        }
    }

    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            cf[i][j] = cf[i][j-1]+a[i][j];
        }
    }


/*    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++){
            cout<<cf[i][j]<<" ";
        }cout<<"\n";
    }*/
    ll q, n,m,w,x,y,z, res;

    cin>>q;
    while(q--){
        cin>>n>>m;
        w = n/m;
        x = w/10;
        y = w%10;
        z = m%10;
        res = 0;
        if(m>n || (z == 0) ){    cout<<0<<"\n";  }
        else{
            
            res = x*cf[z][10];
            res += cf[z][y];
            
            cout<<res<<"\n";
        }
    }
    return 0;
}