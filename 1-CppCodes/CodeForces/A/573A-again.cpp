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

int f(int in){
    int a = in;
    while(a%2==0){ a=a/2;  }
    while(a%3==0){ a=a/3;  }
    return a;
}

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

    int n,a,minimus;
    cin>>n;
    cin>>a;
    minimus = f(a);
    for(int i=1; i<n; i++){
        cin>>a;
        if(minimus != f(a)){    cout<<"No\n"; return 0; }
    }
    cout<<"Yes\n";
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/