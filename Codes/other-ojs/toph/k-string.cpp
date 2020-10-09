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

    ll N, k;
    string s;
    int count[26]={0};

    cin>>N>>k;
    cin>>s;

    int ch='0';
    for(int i=0; i<N; i++){
        ch = s[i];
        if(ch>='A' && ch<='Z'){ ch=ch-'A'; }
        else{   ch=ch-'a';  }
        count[ch]++;
    }

    vector<int> v;
    for(int i=0; i<26; i++){    if(count[i]!=0)v.push_back(count[i]);   }

    sort(v.begin(), v.end());

    int m = v.size();
    N = N-v[m-1]-v[m-2]-v[m-3];

    cout<<N<<"\n";

    return 0;
}