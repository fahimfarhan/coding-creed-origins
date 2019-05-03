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
    
    cout << setprecision(10);
    // cout << num1 << endl;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,r,  *x; double *y;
    cin>>n>>r;
    x = new int[n+1];
    y = new double[n+1];

    for(int i=0; i<n; i++){ cin>>x[i]; y[i]=0;  }

    y[0]=r;

    int d = r<<1;
    double dx=0, dy=0, tempy=0;

    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            dx = abs(x[i]-x[j]);
            if(dx>d){ tempy=r; }
            else{ dy = d*d-dx*dx; dy = sqrt(dy);  tempy = dy + y[j];  }

            y[i] = max(y[i], tempy);
        }

        
    }

    for(int i=0; i<n; i++){ cout<<y[i]<<" ";    }
    cout<<"\n";
    if(!x)delete[] x;
    if(!y)delete[] y;

    
    return 0;
}
