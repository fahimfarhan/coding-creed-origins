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

int n, *a;

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
    a = new int[n+1+1];

    for(int i=0; i<n+2; i++){   a[i]=0; }
    a[2] = 1;
    for(int i=3; i<n+2; i+=2){  a[i] = 1; }

    int currentColor = 0, newColor=0, maximus = 0;
    for(int i=2; i<n+2; i++){
        currentColor = a[i];
        newColor = currentColor+1;

        // maximus = max(maximus, newColor);

        for(int j=i+i; j<n+2; j+=i){
            a[j] = newColor;
        }
    }

    for(int i=2; i<n+2; i++){   maximus = max(maximus, a[i]);   }

    cout<<maximus<<"\n";
    for(int i=2; i<n+2; i++){   cout<<a[i]<<" ";    }cout<<"\n";

    delete[] a;
    return 0;
}
