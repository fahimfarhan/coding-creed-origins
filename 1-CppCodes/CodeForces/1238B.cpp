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

    ll cnt, q, minus, n, r, b;

    cin>>q;
    while(q--){
        cin>>n>>r;
        set<ll> a;
        for(int i=0; i<n; i++){ cin>>b; a.insert(b);  }
        // sort(a.begin(), a.end());

        minus = 0; cnt = 0;

        set<ll>::reverse_iterator it;
        for(it=a.rbegin(); it!=a.rend(); it++){
            b = (*it);
            b-=minus;
            
            if(b <=0 ){ break;  }
            cnt++;
            minus+=r;
        }
        cout<<cnt<<"\n";
    }


    return 0;
}

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
