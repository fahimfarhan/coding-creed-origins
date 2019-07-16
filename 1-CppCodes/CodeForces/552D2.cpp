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
int dx[2005][2005];
int dy[2005][2005];

void preproess(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dx[i][j] = x[i]-x[j];
            dy[i][j] = y[i]-y[j];
        }
    }
}

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

    preproess();
    mycount=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //if(i!=j)
            for(int k=j+1; k<n; k++){
              	bool b1 = (dy[i][j])*(dx[i][k]) == (dy[i][k])*(dx[i][j]);
                bool b2 = (dy[i][j])*(dx[j][k]) == (dy[j][k])*(dx[i][j]);
                if( !(b1 | b2)  ){
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