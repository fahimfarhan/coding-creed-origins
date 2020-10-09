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

ll T, N,M,pos, *a;
double mean1, sum,sum2,delta;
bool b;

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
    while(T--){
        cin>>N;
        M = N-1;
        a = new ll[N+1];
        sum = 0;
        for(int i=1; i<=N; i++){ cin>>a[i]; sum+=a[i];  }

        mean1 = sum/N;
        sum2 = mean1*M;
        delta = sum - sum2;

        b = false; 
        for(int i=1; i<=N; i++){ if(a[i] == delta){ pos = i; b = true; break; }    }
        if(b)
            cout<<pos<<"\n";
        else
            cout<<"Impossible\n";
        delete[] a;
    }
    return 0;
}