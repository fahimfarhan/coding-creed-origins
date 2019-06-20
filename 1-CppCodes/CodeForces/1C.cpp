#ifdef _WIN32

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

#else

#include <bits/stdc++.h>

#endif

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

    double a[3];
    double x[3], y[3];

    for(int i=0; i<3; i++){     cin>>x[i]>>y[i];   }

    a[0] = (x[0]-x[1])*(x[0]-x[1]) + (y[0] - y[1])*(y[0] - y[1]) ;
    a[01] = (x[02]-x[1])*(x[02]-x[1]) + (y[02] - y[1])*(y[02] - y[1]) ;
    a[02] = (x[0]-x[2])*(x[0]-x[2]) + (y[0] - y[2])*(y[0] - y[2]) ;

    for(int i=0; i<3; i++){ a[i] = sqrt(a[i]); }

    sort(a,a+3);

    double area = a[0]*a[1];

    cout << setprecision(8);
    cout << area << endl;
    
    
    return 0;
}
