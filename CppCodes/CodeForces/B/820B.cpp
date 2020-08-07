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

    int n, a;
    cin>>n>>a;
    double A = 1.0*(n-2)*180/n;
    double B = 90 - A/2;

    int v1 = n; int v2 = n-1; int v3=0;

    double temp, minimus = INT_MAX;
    for(int i=1; i<=n-2; i++){
        temp = B*i;
        temp = abs(temp - a);
        if(temp<minimus){   
            minimus = temp; v3 = i;
        }
    }

    cout<<v1<<" "<<v2<<" "<<v3<<"\n";
    
    return 0;
}
