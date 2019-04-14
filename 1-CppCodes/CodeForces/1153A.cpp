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

    int *vs,*vd;
    int s,t,n,d;
    int *a;
    cin>>n>>t;
    int N = 200010;
    a = new int[N];
    vs = new int[n+1];
    vd = new int[n+1];
    for(int i=0; i<N; i++){ a[i]=0; }

    for(int i=01; i<=n; i++){
        cin>>vs[i]>>vd[i]; 
    }
    int stop=0;
    for(int i=01; i<=n; i++){
        s = vs[i]; d = vd[i];
        stop = max(s+1, t+d+1);
        for(int j=s; j<stop; j+=d){
            if(a[j]==0){a[j]=i;}
        }
        if(a[t]!=0){    break; }
    }
    while(t<N){
        if(a[t]!=0){    break; }
        t++;
    }
    cout<<a[t]<<"\n";
    delete[] a;
    delete[] vs; 
    delete[] vd;

    return 0;
}