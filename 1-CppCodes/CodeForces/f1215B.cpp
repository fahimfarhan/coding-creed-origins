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

    ll n;
    cin>>n;
    int a[n]={0};

    ll b;
    for(int i=0; i<n; i++){ cin>>b; if(b<0){    a[i] = 1;   }   }
    // convert into cf
    for(int i=1; i<n; i++){ a[i] +=a[i-1];  }

    ll ans1 = 0;
    ll one = 1;
    ll temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            temp = a[j]-a[i];
            if(temp&one==one){  ans1++; }
        }
    }

    ll ans2 = (n*(n-1)/2)-ans1;
    cout<<ans1<<" "<<ans2<<"\n";

    return 0;
}