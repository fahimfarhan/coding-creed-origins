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

    int n, *a;

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
    a = new int[n+1];

    for(int i=0; i<n; i++){    cin>>a[i];  }

    //int i1=0, j1=0;
    for(int i=1; i<n-1; i++){
        //i1 = max(i,i1);
        for(int j=1; j<n-1;j++){
            //j1 = max(j,j1);
            if( (a[j-1]<=a[j]) && (a[j]<=a[j+1]) ){
                continue;
            }else{
                swap(a[j-1], a[j+1]);
            }
        }
    }

    //cout<<i1<<" "<<j1<<"\n";
    //for(int i=0; i<n; i++){ cout<<a[i]<<" "; }cout<<"\n";

    bool b = true;
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            cout<<i<<"\n";
            b = false; break;
        }
    }

    if(b){  cout<<"OK\n";   }

    delete[] a;
    
    return 0;
}
