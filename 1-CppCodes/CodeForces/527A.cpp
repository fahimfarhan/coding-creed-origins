/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll int64_t
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

    ll a,b,count, r,d;



    cin>>a>>b;
    // a > b
    /*
    while(a>0 && b>0){
        d = a/b;
        count+=d;
        r = a%b;
        b=a; a = r;
        // swap(a,b);
    }*/
    count = 0;
    while(a>0 && b>0){
        if(a>=b){
            d = a/b;
            a = a%b;
            count+=d;
        }else{
            d = b/a;
            b = b%a;
            count+=d;
        }
    }

    cout<<count<<"\n";

    return 0;
}