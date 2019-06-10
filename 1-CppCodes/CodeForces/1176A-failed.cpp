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

//    a[0] = 01;
//    cout<<a[0]<<"\n";

    int t, ans;
    int64_t x;

    cin>>t;
    int p,q,r;
    while(t--){

        cin>>x;

        p=0; q=0; r=0;
        
        while( (x%5) == 0){
            x = x/5;
            p++;
        }        
        while( (x%3) == 0){
            x = x/3;
            q++;
        }        
        while( (x%2) == 0){
            x = x/2;
            r++;
        }

        if(x == 1){
            // ans = (1<<(2*p)) + (1<<q)+r;
            ans = pow(4,p)+pow(2,q)+r;
            cout<<ans<<"\n";
        }else{
            cout<<"-1\n";
        }
        
    }

    return 0;
}
