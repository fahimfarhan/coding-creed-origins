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
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,x, *a;
    cin>>n;
    a = new int[n+1];
    for(int i=0; i<n; i++){ cin>>a[i];  }
    sort(a,a+n);

    if(a[0]==a[(n>>1)]){    cout<<"Bob\n";    }
    else{   cout<<"Alice\n";  }
    delete[] a;


    
    return 0;
}
