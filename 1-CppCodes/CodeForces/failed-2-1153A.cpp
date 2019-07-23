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
    int minimus,Index,r,n,t,temp, *vs,*vd,s,d;
    cin>>n>>t;
    vs = new int[n+1];
    vd = new int[n+1];
    for(int i=01; i<=n; i++){    cin>>vs[i]>>vd[i];  }

    int ans = 1;

    minimus = INT_MAX;
    Index = 1;
    for(int i=1; i<=n; i++){
        s = vs[i]; d=vd[i];

        temp = t - s;
        r = temp%d;
        if(r==0){    Index = i; break; }
        else{
            r = d-r;
            if(r<minimus){  minimus = r; Index=i;   }
        }
    }

    cout<<Index<<"\n";
    delete[] vs; delete[] vd;
    return 0;
}
