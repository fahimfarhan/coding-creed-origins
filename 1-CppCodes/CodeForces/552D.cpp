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

int *x, *y;
int n, mycount;

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
    x = new int[n+1]; y = new int[n+1];

    for(int i=0; i<n; i++){ cin>>x[i]>>y[i];    }

    mycount=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //if(i!=j)
            for(int k=j+1; k<n; k++){
              	if(x[i]*(y[j]-y[k])+x[j]*(y[k]-y[i])+x[k]*(y[i]-y[j])!=0){
					mycount++;
				}
            }
        }
    }
    //mycount=mycount>>1;
    cout<<mycount<<"\n";

    delete[] x; delete[] y;
    return 0;
}