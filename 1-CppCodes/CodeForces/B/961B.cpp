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

int n,k;
ll *a;
//ll *cf;
ll *cft;

int *t;
int t1;

ll rangedQueryA(int start, int end){
    if(end<start){  return 0; }
    return a[end]-a[start-1];
}

ll rangedQueryAT(int start, int end){
    if(end<start){  return 0; }
    return cft[end]-cft[start-1];
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

    cin>>n>>k;
    //t = new int[n+1];
    a = new ll[n+1];
    cft = new ll[n+1];
    for(int i=0; i<=n; i++){    a[i]=0; cft[i]=0;  }

    for(int i=1; i<=n; i++){    cin>>a[i]; cft[i]=a[i];  }
    for(int i=1; i<=n; i++){    cin>>t1;
            a[i]=a[i]+a[i-1];
            cft[i] = cft[i]*t1+cft[i-1];
    
    }
    


    ll first, mid, last, maximus,I, temp;
    maximus = 0; I=0;
    for(int i=1; i<=n-k+1; i++){
        first = rangedQueryAT(1,i-1);
        mid = rangedQueryA(i,i+k-1);
        last = rangedQueryAT(i+k, n);
        temp = first+mid+last;
        maximus = max(maximus, temp);        
    }
    cout<<maximus<<"\n";
    if(!a)delete[] a;
    if(!cft)delete[] cft;
    //if(!t)delete[] t;
    return 0;
}
