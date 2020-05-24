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

    ll T,n, m, zeroCount, nonZeroCount, nonZeroVlue;
    string s,t;
    cin>>T;

    while(T--){
        cin>>n;
        cin>>s;
        cin>>t;

        zeroCount = 0;
        nonZeroCount = 0;
        nonZeroVlue = 0;
        for(int i=0; i<n; i++){
            m = s[i]^t[i];
            if(m==0){   zeroCount++;    }
            else{   
                if(nonZeroVlue==0){ nonZeroVlue=m; nonZeroCount++;  }
                else{
                    if(nonZeroVlue==m){ nonZeroCount++; }
                    else{   nonZeroVlue=0; break;   }
                } 
            
            }
        }
        if( (nonZeroCount==2) && (zeroCount == (n-nonZeroCount)) && (nonZeroVlue!=0) ){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }

    }
    return 0;
}

