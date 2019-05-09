#include <bits/stdc++.h>
using namespace std;
#define MODULO 1e9+7
#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18

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
    int n,k,x,*a;

    set< pair<int,int> > s;

    cin>>n>>k;

    a = new int[n+1];
    for(int i=0; i<=n; i++){    a[i]=0; }
    for(int i=0; i<k; i++){
        cin>>x;

        if(a[x-1]>0){   s.insert({x-1,x});   }
        if(a[x+1]>0){   s.insert({x+1,x});   }
        s.insert({x,x});
        a[x]++;
    }
    int ans = (n-2)*3+4;
    if(n==1){   ans=1;  }
    ans-=s.size();
    cout<<ans<<"\n";
    delete[] a;
    
    return 0;
}
