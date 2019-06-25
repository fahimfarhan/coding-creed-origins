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

map<double, bool> mp;
int n,  *x, *y;
bool infCount;
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

    infCount = 0;
    cin>>n;
    x = new int[n+1]; y = new int[n+1];

    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }

    double slope = 0;
    map<double,bool>::iterator it;
    int ans = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(i!=j){
                if( (x[i]-x[j])== 0 ){  
                    infCount=1; 
                    ans+=mp.size();
                }
                else{
                    slope = 1.0*(y[i]-y[j])/(x[i]-x[j]);
                    for(it = mp.begin(); it!=mp.end(); it++){
                        if( (it->first)!=slope)ans++;
                    }
                    mp[slope]=1;
                    if(infCount){   ans++; }
                }
            }
        }
    }
    cout<<ans<<"\n";
    delete[] x; delete[] y;



    return 0;
}
