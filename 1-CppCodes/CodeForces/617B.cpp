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
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,*a;
    ll res;
    int continuousZeroes=0, countOnes=0;
    cin>>n;
    a = new int[n+1];

    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==1) countOnes++;
    }

    if(countOnes==1){   cout<<1<<"\n"; exit(0); }
    else if(countOnes==0){ cout<<0<<"\n"; exit(0); }
    a[n]=0;
    res = 1;
    int j=0; 
    for(int i=0; i<n; i++){ if(a[i]==1) {j=i; break;} }
    continuousZeroes = 0;
    int start = j+1;
    //cout<<start<<"\n";
    
    for(int i=start; i<=n; i++){
        continuousZeroes++;
        if(a[i]==1){
            res = res*continuousZeroes;
      //      cout<<i<<" "<<res<<"\n";
            continuousZeroes=0;
        }
    }

    cout<<res<<"\n";

    if(!a)delete[] a;
    return 0;
}
