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


// int n,m;
vector<int> *g;
bool *isvisited;

int **b;
int N = 100;
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

    b = new int*[N+1];
    for(int i=0; i<=N; i++){    b[i]=new int[N+1];  }

    b[0][0]=1;

    for(int i=1; i<=N; i++){    
        b[i][0] = b[i-1][i-1];  

        for(int j=1; j<=i; j++){
            b[i][j]=b[i-1][j-1]+b[i][j-1];
        }
    }

    int n,k;
    
    cin>>n>>k;
    cout<<b[n][k]<<"\n";

    for(int i=0; i<=N; i++){   delete[] b[i];  }
    delete[] b;
    return 0;
}
