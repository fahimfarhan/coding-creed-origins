#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int n; bool *is_prime;
vector<int> v;

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
    is_prime = new bool[n+1];
    for(int i=0; i<=n; i++){    is_prime[i] = 1;    }

    is_prime[0]=0; is_prime[1] = 0;

    for(int j=2+2; j<=n; j+=2){
        is_prime[j] = 0;
    }
    
    for(int i=3; i<=n; i+=2){
        if(is_prime[i]){
            for(int j=i+i; j<=n; j+=i){
                is_prime[j] = 0;
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(is_prime[i]){
            int q = 1;
            while(q<=(n/i)){
                q = q*i;
                v.push_back(q);
            }
        }
    }

    n = v.size();

    cout<<n<<"\n";
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }cout<<"\n";

    delete[] is_prime;
    return 0;
}
