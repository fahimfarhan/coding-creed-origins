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
    
    for(int i=1; i<=d; i++ ){
        if( (i%l==0) || (i%m==0) || (i%n==0) || (i%k==0) )
        { count++;    }
    }
    cout<<count<<"\n";

    //delete[] a;


    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/