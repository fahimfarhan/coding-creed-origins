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
bool *ok;
int N = 4000001;

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

    int x,t;
    x=0; t=0; 
    ok = new bool[N];
    for(int i=1; i<N; i= (i<<1) ){ ok[i-1]=1; }

    cin>>x;

    int y, cnt, tp;
    vector<int> v;
    while(ok[x]!=1){
        y=x; 
        cnt=0; tp=1;

        while( (y&1)==0 ){
            y=(y>>1);
            cnt++;
            tp=(tp<<1);
        }
        tp--;
        v.push_back(cnt);
        x=x^tp;
        t++;
        if(ok[x]){  break; }
        x++; 
        t++;
    }

    cout<<t<<"\n";
    N = v.size();
    for(int i=0; i<N; i++){
        cout<<v[i]<<" ";
    }cout<<"\n";

    if(!ok)delete[] ok;
    return 0;
}
