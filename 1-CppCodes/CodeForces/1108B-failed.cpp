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
    /* Soln soln */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, *a;
    short *b;
    cin>>n;
    a = new int[n+1];
    b = new short[130];
    for(int i=0; i<130; i++){   b[i] = 0; }
    
    for(int i=0; i<n; i++){ cin>>a[i]; b[a[i]]++;  }

    sort(a,a+n);

    int maximus = a[n-1];
    b[1]--;
    b[maximus]--;
    int stop = maximus/2;
    for(int i=2; i<=stop; i++){
        if( (maximus%i) ==0 ){
            b[i]--;
        }
    }
    /*for(int i=0; i<n-1; i++){
    }*/
    maximus = 0;
    for(int i=0; i<n; i++){
        if(b[a[i]]==1){    maximus = a[i]; }
    }

    cout<<maximus<<" "<<a[n-1]<<"\n";

    if(!a)delete[] a;

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/