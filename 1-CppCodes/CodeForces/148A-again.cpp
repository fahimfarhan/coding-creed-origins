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

    int l,m,n,k,d, count;
    //bool *a;

    count = 0; 

    cin>>k>>l>>m>>n>>d;
    int temp1=lcm(k,l), temp2=lcm(l,m), temp3=lcm(k,m);
    
    count = count + d/k + d/l + d/m + d/n;
    count = count - d/temp1 -d/temp3-d/lcm(k,n)-d/temp2-d/lcm(l,n)-d/lcm(m,n);
    count = count + d/ lcm(temp1, m) + d/lcm(temp1, n) + d/lcm(temp2, n) + d/lcm(temp3, n);
    count = count - d/lcm(temp1, lcm(m,n));

    cout<<count<<"\n";

    //delete[] a;


    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/