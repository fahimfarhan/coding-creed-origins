/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
/**
Dread it, run from it, destiny arrives all the same !
I find your lack of faith in the CodeForces disturbing! >_<
Love you 3000 !
Keep It Simple Stupid (KISS)!
Good Hunting 47!
*/
/**
AC I - Redemption AC II - Revenge AC: Brotherhood - Justice AC: Revelation - Answers 
AC III - Freedom AC IV - Glory AC Rogue - Betrayal AC Unity - Love AC Syndicate - Family 
AC Origins - Beginnings 
*/

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

ll mypow(const ll& n, const ll& p){
    ll ret=1;
    for(int i=0; i<p; i++){ ret*=n; }
    return ret;
}

int sod(const int64_t& n){
    int64_t a = n;
    int sum = 0;
    while(a){  sum+=a%10;   a=a/10; }
    return sum;
}

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

    ll a,b,c;
    cin>>a>>b>>c;

    int64_t x, maximus = 1000000000;

    vector<int64_t> v;
    for(int i=1; i<=80; i++){
        x = b*mypow(i,a)+c;
        if( (x>0) && (x<maximus) && (i==sod(x)) ){   v.push_back(x);  }
    }

    cout<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++){  cout<<v[i]<<" ";    }
    cout<<"\n";


    return 0;
}