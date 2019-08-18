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

    int n;
    int64_t res = 0;

    
    ll one = 1, mone = -1;

    cin>>n;
    ll a=0, negCount=0, zeroCount = 0;
    for(int i=0; i<n; i++){    
        cin>>a;
        if(a == 0){
            zeroCount++;
        }  
        else if(a<0){
            res+= mone - a;
            negCount++;
        }else{  
            
                res+=a-one;
            
        }
    }

    if( ((negCount%2)==1) && (zeroCount>0) ){  res+=1; zeroCount--; }
    else if(((negCount%2)==1) && (zeroCount==0)){   res+=2; }

    res+=zeroCount;
    
    cout<<res<<"\n";

    return 0;
}