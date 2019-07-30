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

    double h,l;
    double r=0, r3=0, r1 = 0, r2=0;
    cin>>h>>l;

    r1 = 1.0*(h);
    r1 = r1/2;

    r2 = 1.0*l/2;
    r3 = 1.0*l/h;
    r2 = r2*r3;

    r = r1+r2;
    


    cout << setprecision(8);
    cout << (r-h) << endl;



    return 0;
}