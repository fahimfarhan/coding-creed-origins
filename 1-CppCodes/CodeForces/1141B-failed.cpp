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

    int n;
    bool *a;
    cin>>n;
    a = new bool[n+1];
    for(int i=0; i<n; i++){ cin>>a[i]; }

    int temp=0, maximus = 0, pos;
    for(int i=0; i<n; i++){
        if(a[i] == 1){  temp++; pos = i; 
            if( (pos == (n-1) ) && (temp>=maximus) ){ maximus++; }
        }
        else{ maximus = max(temp, maximus); temp=0;  }
    }

    cout<<maximus<<"\n";

    if(!a)delete[] a;

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/