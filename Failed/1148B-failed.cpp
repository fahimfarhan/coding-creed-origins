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

int n,m,k;
ll ta,tb;
ll *a, *b;

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

    cin>>n>>m>>ta>>tb>>k;

    a = new ll[n+1];
    b = new ll[m+1];

    for(int i=0; i<n; i++){ cin>>a[i]; a[i]+=ta;  }
    for(int i=0; i<m; i++){ cin>>b[i];  }

    // case 1: k>=n || m: 
    if(k>=n || k>=m){
        cout<<"-1\n";
    }else{
        ll firstJourneyEnd=0;
        ll secoundJourneyEndTime=0;
        int index=0;
        ll maximus = 0;
        for(int x=1; x<=min(k,n); x++){
            firstJourneyEnd = a[x];

            index = upper_bound(b,b+m, firstJourneyEnd)-b;

            if(index >= m){
                maximus = -1;
                break;
            }else{
                secoundJourneyEndTime = b[index]+tb;
                maximus = max(maximus,secoundJourneyEndTime);
            }
        }

        cout<<maximus<<"\n";    
    }

    delete[] b;
    delete[] a;

    return 0;
}
