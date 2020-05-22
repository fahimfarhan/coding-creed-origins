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

map<int,int> mp;

bool f(const int& N,const int& count){
    // cout<<N<<" "<<count<<"\n";
    if(N==0){   return false;   }
    if(mp[N]>=count){   return true;    }
    int M = N>>1;
    int C = (count-mp[N])<<1;
    return f(M,C);
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

    ll q,m,n;
    cin>>q;
    while(q--){
        for(int j=1; j<=2048; j=(j<<1)){
            mp[j] = 0;
        }
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>m;
            if(m<=2048){
                mp[m]++;
            }
        }
        bool b = f(2048,1);
        if(b){  cout<<"YES\n";  }
        else{   cout<<"NO\n";  }
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
