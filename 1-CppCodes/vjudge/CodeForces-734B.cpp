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

    ll sum=0, a=0, b=0, maximus=0, minimus = INT_MAX;

    ll k2,k3,k5,k6;

    cin>>k2>>k3>>k5>>k6;
    minimus = min(k2, k5);
    minimus = min(minimus, k6);

    k2-=minimus;

    sum = 256*minimus;

    minimus = min(k3, k2);
    //minimus = min(minimus, k3);

    sum = sum+32*minimus;
    
    cout<<sum<<"\n";
    return 0;
}


