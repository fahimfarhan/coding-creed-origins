#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

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

    int n,m;
    ll **a;
    ll minimus, maximus;

    minimus = INT_MAX;
    maximus = -1;

    cin>>n>>m;
    a = new ll*[n+1];
    for(int i=0; i<=n; i++){    a[i] = new ll[m+1]; }

    for(int i=0; i<n; i++){
        minimus = INT_MAX;
        for(int j=0; j<m; j++){
            cin>>a[i][j]; if(a[i][j]<minimus){  minimus = a[i][j];  }
        }
        if(minimus>maximus){    maximus=minimus; }
    }
    cout<<maximus<<"\n";    

    for(int i=0; i<=n; i++){    delete[] a[i];  }
    delete[] a;
    return 0;
}
