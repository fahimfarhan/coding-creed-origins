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

int n;
int *a;


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
    a = new int[n+1];
    isvisited = new bool[n+1];
    g = new vector<int>[n+1];
    for(int i=0; i<n; i++){ cin>>a[i];  }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int u = a[i]; int v = a[j];
            if( (u&v) != 0){
                g[u].push_back(v); g[v].push_back(u);
            }
        }
    }

    for(int i=0; i<n; i++){ isvisited[i] = false; }
    
    

    delete[] a;
    delete[] isvisited;
    return 0;
}