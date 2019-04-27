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
    int N=4000001;
    int ok[N];

    for(int i=1; i<N; i=(i<<1)){ ok[i-1]=1; }
    
    int x,t;
    x=0,t=0;
    cin>>x;

    vector<int> v;
    int y=0, tp=0, mycount=0;
    while(ok[x]!=1){
        y=x;
        tp=1;
        mycount=0;
        while( (y&1)==0 ){  
            y=(y>>1);
            mycount++;
            tp = (tp<<1);
        }
        tp--;
        v.push_back(mycount);
        x = x^tp;
        t++;
        if(ok[x]==1){ break; }
        x++; t++;
    }
    cout<<t<<"\n";
    for(int i=0; i<v.size(); i++){  cout<<v[i]<<" "; }
    cout<<"\n";
    return 0;
}
