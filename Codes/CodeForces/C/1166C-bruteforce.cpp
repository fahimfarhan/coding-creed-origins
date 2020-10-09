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


// int n,m;
vector<int> *g;
bool *isvisited;

int n;
ll mycount, x,y,ax,ay,axmy,axpy,*a;

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
    a = new ll[n+1];

    for(int i=0; i<n; i++){ cin>>a[i];  }


    mycount = 0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            x = a[i]; y = a[j];
            ax = abs(x); ay = abs(y);
            if(ax>ay){  swap(ax,ay);    }
            axmy = abs(x-y); axpy = abs(x+y);
            if(axmy>axpy){  swap(axmy, axpy);   }

            if( (axmy <=ax) && (axpy>=ay) ){ mycount++; }

        }
    }

    cout<<mycount<<"\n";

    delete[] a;
    return 0;
}
