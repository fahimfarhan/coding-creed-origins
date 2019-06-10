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

    int n,x,y,res, a[100], count[6];

    for(int i=0; i<100; i++){ a[i]=-1; }
    a[4]=0; a[8]=1; a[15]=2; a[16]=3; a[23]=4; a[42]=5;
    
    for(int i=0; i<6; i++){ count[i]=0; }


    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        y = a[x];
        if(y==0){
            count[y]++;
        }
        else 
        if( (y!=-1) && (count[y-1]>0) ){
            count[y-1]--;
            count[y]++;
        }
    }
    
    res = n - count[5]*6;

    cout<<res<<"\n";

    return 0;
}
