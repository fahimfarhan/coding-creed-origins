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

    int a[10];
    int g=0,p=0;

    for(int i=2; i<6; i++){
        //cout<<"? 1 "<<i<<"\n";
        printf("? 1 %d\n",i);
        fflush(stdout);
        cin>>a[i];
        g = __gcd(g,a[i]);
    }

    if((g==30) || (g==46)){    g = g>>1;   }

    cout<<"! "<<g<<" ";

    p=g;

    for(int i=2; i<6; i++){
        cout<<(a[i]/g)<<" ";
        p = p*(a[i]/g);
    } 

	cout<<(4*8*15*16*23*42)/p<<endl;	

    return 0;
}

/*16
64
345
672*/