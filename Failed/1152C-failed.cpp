#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int ans, K;

int f(int a, int b, int q){
    int k = q - (a%q);
    if((a%q)==0){ k=0;    }
    a+=k; b+=k;
    int mylcm = (a)*(b)/(__gcd(a,b));

    if(mylcm<ans){
        ans = mylcm;
        return k;
    }
    return k;
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
    K = INT_MAX;
    ans = INT_MAX;
    int a,b;
    cin>>a>>b;

    if(a>b){    swap(a,b);  }

    int stop = sqrt(b-a)+1;

    for(int q=1; q<=stop; q++ ){
        if( (((b-a)%q) ==0) && ( (a%q) == (b%q) )){
            K = f(a,b,q);
            K = f(a,b,(b-a)/q); // min(K,f(a,b,(b-a)/q));
        }
    }

    cout<<K<<"\n";
    return 0;
}
