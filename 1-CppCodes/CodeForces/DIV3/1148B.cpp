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

    for(int i=0; i<n; i++){ cin>>a[i];  }
    for(int i=0; i<m; i++){ cin>>b[i];  }

    int ptrA=0;

    bool flag=true;
    for(int i=0; i<m; i++){
        if(!flag){  break; }
        if( (ptrA<n) && a[ptrA]+ta <=b[i] ){
            ptrA++;
            k--;
            if(k==-1){
                cout<<(b[i]+tb)<<"\n";
                flag = false; 
                break;
            }
        }
    }

    if(flag){   cout<<"-1\n";   }

    delete[] b;
    delete[] a;

    return 0;
}
