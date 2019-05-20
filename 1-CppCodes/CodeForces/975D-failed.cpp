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
ll a,b,Gx, *x, *Vx, *Vy;

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

    cin>>n>>a>>b;
    x = new ll[n+1]; Vx = new ll[n+1]; Vy  = new ll[n+1];


    for(int i=0; i<n; i++){     cin>>x[i]>>Vx[i]>>Vy[i];    }


    Gx = 0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if( (Vx[i]==Vx[j]) && (Vx[i]==0) ){
                if(Vy[i]!=Vy[j]){   Gx+=2;}
            }/*else if(Vx[i]*Vy[j] == Vx[j]*Vy[i]){
                // do nothing
            }*/else if( (a*Vx[i]-Vy[i])==(a*Vx[j]-Vy[j]) ){
                Gx+=2;
            }
        }
    }
    
    cout<<Gx<<"\n";

    delete[] x; delete[] Vx; delete[] Vy;
    return 0;
}
