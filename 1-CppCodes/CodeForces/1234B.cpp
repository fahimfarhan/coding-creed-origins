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

map<ll,bool> mp;
ll chat[210];
int n,k;
int head=0, tail=0;

ll a;

bool isDiffK(){
    if(head-tail+1 == k ){  return true; }
    return false;
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

    cin>>n>>k;

    head = -1; tail = 0;

    for(int i=0; i<n; i++){
        cin>>a;
        if(!mp[a]){
            if(!isDiffK() ){
                head++;
                chat[head] = a;
                mp[a] = 1;
            }else{
                head++;
                chat[head] = a;
                mp[a] = 1;
                a = chat[tail];
                mp[a] = 0;
                tail++;
            }
        }

    }

    int m = head - tail+1;
    cout<<m<<"\n";
    for(int i=head; i>=tail; i--){
        cout<<chat[i]<<" ";
    }cout<<"\n";
    


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
