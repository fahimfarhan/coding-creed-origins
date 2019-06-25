#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

set< double > s;
bool infCount;
bool zeroCount;

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
    infCount=0;
    zeroCount=0;

    int *x , *y;
    cin>>n;
    x = new int[n+1]; y = new int[n+1];

    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }

    double slope;
    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                // slope = (y1-y2)/(x1-x2)
                if( (x[i]-x[j]) == 0){  infCount=1; }
                //else if()
                else{
                    slope = 1.0*(y[i]-y[j])/(x[i]-x[j]);
                    if(s.find(slope)==s.end()){ 
                        // not found 

                    }
                    s.insert(slope);
                }
            }
            
        }
    }

    n = s.size();
    if(infCount){   n++; }

    int ans = n*(n-1); ans=ans>>1;

    cout<<ans<<"\n";

    delete[] x; delete[] y;
    return 0;
}
