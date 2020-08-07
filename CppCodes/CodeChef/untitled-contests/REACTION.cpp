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
int **a;

int r,c, T;
bool b ;

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


    cin>>T;

    while(T--){
        cin>>r>>c;
        a = new int*[r+1];
        for(int i=0; i<=r; i++){    a[i] = new int[c+1];    }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>a[i][j];
            }
        }

        b = true;

        // case 1: 4 corners
        if(a[0][0]>1){  b = false;}
        else if(a[0][c-1]>1){   b=false; }
        else if(a[r-1][0]>1){   b=false; }
        else if(a[r-1][c-1]>1){   b=false; }
        
        //case 2: 4 borders
        if(b){
            for(int i=1; i<c-1; i++){
                if( (a[0][i]>2) || (a[r-1][i]>2) ){ b=false; break; }
            }
           for(int i=1; i<r-1; i++){
                if( (a[i][0]>2) || (a[i][c-1]>2) ){ b=false; break; }
            }
        }
        //case 3: inside 
        if(b){
            for(int i=1; i<r-1; i++){
                for(int j=1; j<c-1; j++){
                    if(a[i][j]>3){b=false; break; }
                }
            }
        }

        if(b){  cout<<"Stable\n";   }
        else{   cout<<"Unstable\n"; }

        for(int i=0; i<=r; i++){    if(!a[i]) delete[] a[i];    }
        delete[] a;
    }


    return 0;
}
