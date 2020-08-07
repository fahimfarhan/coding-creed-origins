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

    int n;
    cin>>n;
    int a[n+1]={0};
    bool b[n+1]={false};

    for(int i=0; i<n; i++){  cin>>a[i]; }
    sort(a,a+n); 

    int count = 0; 
    int remaining = n;

    int curr = 0;
    for(int i=0; i<n; i++){
        if(remaining == 0){ break;  }
        if(b[i]==false){
            b[i] = true;
            curr = a[i];
            //cout<<curr<<"\n";
            count++;
            remaining--;
            for(int j=i+1; j<n; j++){
                if( (b[j]==false) && ( (a[j]%curr) == 0) ){
                    b[j] = true;
                    remaining--;
                }
            }
        }
    }

    cout<<count<<"\n";

    return 0;
}