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

int n, *a;

int f(int l, int r, int h){
    int ret = 0; 
    if(r<l) {   return 0;   }
    //if(r==l){   return 1;   }
    int m = min_element(a+l, a+r+1)-a;
    int vertical, horizontal;
    vertical = r-l+1;
    horizontal = f(l,m-1,a[m])+f(m+1,r, a[m]) +a[m] - h;
    ret = min(vertical, horizontal);

    return ret;
}
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

    cin>>n; 
    a = new int[n+1];
    for(int i=0; i<n; i++){ cin>>a[i];  }

    int ans = f(0,n-1,0);
    cout<<ans<<"\n";

    if(!a)delete[] a;
    return 0;
}
