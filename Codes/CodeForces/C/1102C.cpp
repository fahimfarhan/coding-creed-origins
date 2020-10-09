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
    int n,x,y,z,cnt;
    int *a;
    cin>>n>>x>>y;
    a = new int[n+1];
    
    for(int i=0; i<n; i++){ cin>>a[i];  }
    
    if(x>y){    cout<<n<<"\n";  }
    else{
        sort(a,a+n);
        cnt = upper_bound(a,a+n,x)-a;
        cnt = (cnt+1);
        cnt = cnt>>1;
        cout<<cnt<<"\n";
    }
    delete[] a;
    return 0;
}
