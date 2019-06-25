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

ll T, *a;
int N;

void preprocess(){
    a[0]=1;
    // int count = 1;
    for(int i=1; i<N;i++){
        a[i] = ( (i+1)*a[i-1] + MODULO )%MODULO;
    }
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

    cin>>T;
    N = 1000001;
    a = new ll[N+1];
    for(int i=0; i<=N;i++){    a[i] = 1;   }

    preprocess();

    ll n;
    while(T--){
        cin>>n;
        if(n==1){   cout<<1<<"\n";  }
        else{   
            cout<<( (a[(n-1)]*(1+n)-1)%MODULO )<<"\n";
        }
    }

    delete[] a;
    return 0;
}
