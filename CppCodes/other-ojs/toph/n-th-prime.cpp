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

#define N 7000000
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

    bool isPrime[N];

    for(int i=0; i<N; i++){   isPrime[i] = 1; }
    isPrime[0] = 0; isPrime[1]=0; 
    
    for(int i=4; i<N; i+=2){ isPrime[i] = 0;  }
    for(int i=3; i<N; i+=2){
        if(isPrime[i]){
            int start = i+i;
            for(int j=start; j<N; j+=i){
                isPrime[j] = 0; 
            }
        }
    }

    vector<int> v;
    for(int i=2; i<N; i++){ if(isPrime[i]){ v.push_back(i); }   }
    
    int n;
    cin>>n;
    n=n-1;
    cout<<v[n]<<"\n";
    cout<<v.size()<<"\n";
    //for(int i=0; i<v.size(); i++){  cout<<v[i]<<" ";    }cout<<"\n";

    return 0;
}