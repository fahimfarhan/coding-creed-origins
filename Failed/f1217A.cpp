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

    ll T;
    ll str=0, intl=0, expr=0, count=0, temp=0, ul, lb;

    cin>>T;
    while(T--){
        cin>>str>>intl>>expr;

        if(str+expr<=intl){
            count=0;
        }else if(expr == 0){
            count = 1;
        }else{
            temp = str+expr-intl;
            
            if( (temp&1) == 0){ count = temp>>1; }
            else{  count = 1+(temp>>1);  }
        }
        cout<<count<<"\n";
    }

    return 0;
}