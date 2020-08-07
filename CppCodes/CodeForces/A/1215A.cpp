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

    ll minimus, maximus, a1,a2,k1,k2,n;
    cin>>a1;
    cin>>a2;
    cin>>k1;
    cin>>k2;
    cin>>n;
    
    minimus = max((ll)0,n-(k1-1)*a1-(k2-1)*a2);

    // maximus 
    if(k2<k1){
        if(n<=a2*k2){   maximus = n/k2;     }
        else{   maximus = a2+(n-a2*k2)/k1;  }
    }else{
        if(n<=a1*k1){   maximus = n/k1;     }
        else{   maximus=a1+(n-a1*k1)/k2;    }
    }

    cout<<minimus<<" "<<maximus<<"\n";
    return 0;
}