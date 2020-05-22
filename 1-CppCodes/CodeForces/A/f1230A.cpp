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
int *a;
int half=0;
int isvisitedcount = 0, n=0;


bool f(int sum){
    cout<<sum<<"\n";
    // if(isvisitedcount==n){  return false;   }
    if(sum==half){ return true;    }
    if(sum>half){   return false;   }

    bool ret = false;
    for(int i=0; i<n; i++){
        if( (isvisited[i]==0) ){
            isvisited[i] = 1;
            isvisitedcount++;
            int temp = sum  + a[i];
            ret = f( temp );
            isvisited[i] = 0;
            isvisitedcount--;
            if(ret == true){    return true;    }
        }
    }
    return ret;
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

    cin>>n;
    isvisitedcount = 0;
    a = new int[n+1]; isvisited = new bool[n+1];


    for(int i=0; i<n; i++){ cin>>a[i];   }

    int total = 0;
    for(int i=0; i<n; i++){ total+=a[i]; isvisited[i] = 0;    }

    // if(total&1 == 1){   cout<<"NO\n";   exit(0);    }

    half = total>>1;

    bool b = f(0);
    if(b){  cout<<"YES\n";  }
    else{   cout<<"NO\n";   }

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
