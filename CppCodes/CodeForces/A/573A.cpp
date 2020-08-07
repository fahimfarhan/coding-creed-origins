#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

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
    for(int i=0; i<n; i++){ cin>>a[i]; }

    for(int i=0; i<n; i++){
        while(a[i]%2 == 0){ a[i]=a[i]/2; }
        while(a[i]%3 == 0){ a[i]=a[i]/3; }
    }

    for(int i=1; i<n; i++){
        if(a[i]!=a[i-1]){   cout<<"No\n"; return 0;  }
    }
    cout<<"Yes\n";
    delete[] a;
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/