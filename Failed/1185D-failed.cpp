#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
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

    int n;
    ll *a;

    cin>>n;
    a = new ll[n+1];

    set<int> v;
    map<int,int> mp;
    map<int, int> diff;

    for(int i=0; i<n; i++){ cin>>a[i]; mp[a[i]] = i;  }
    sort(a,a+n);

    if(n==2){   cout<<"1\n";   }
    else if(n==3){  if( (a[1]-a[0]) != (a[2]-a[1]) ){ cout<<2<<"\n";   }  }
    else if(n>=4){
        

        for(int i=1; i<n; i++){ a[i]-=a[0]; }

        int mycounter = 0;
        
        for(int i=1; i<n; i++){ if()}


            
        
    }


    delete[] a;
    return 0;
}
