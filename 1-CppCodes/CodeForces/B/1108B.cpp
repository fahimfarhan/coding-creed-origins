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
    
    cin>>n;
    a = new int[n+1];
    
    for(int i=0; i<n; i++){ cin>>a[i];   }

    sort(a,a+n);

    int maximus = a[n-1];
    int j=maximus;
    for(int i=n-2; i>0; i--){
        if( (a[i] == maximus) || ( (maximus%a[i]) != 0) || (a[i] == a[i-1]) ){ j=a[i];  break;  }
    }

    cout<<maximus<<" "<<j<<"\n";

    if(!a)delete[] a;

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/