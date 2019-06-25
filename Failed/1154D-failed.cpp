#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


    int pos, n,a,b, amax;
    int *s;
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


    cin>>n>>b>>a;
    amax = a;
    s = new int[n+1];
    for(int i=0; i<n; i++){ cin>>s[i];  }

    pos = 0;

    cout<<a<<" "<<b<<" here\n";
    while( pos<(n-1) && ((b>0) || (a>0)) ){
        if(pos == (n-1) ){ cout<<a<<" "<<b<<" "<<"c1\n"; break; }
        else if( (b==0) && (a==0) ){ cout<<a<<" "<<b<<" "<<"c2\n"; break; }
        else if( (s[pos]==1) && (b>0) ){   cout<<a<<" "<<b<<" "<<s[pos]<<" "<<"c3\n"; b=b-1; pos=pos-1; if(a<amax){    a=a+1; };  }
        else if( (s[pos]==1) && (b==0) ){ cout<<a<<" "<<b<<" "<<s[pos]<<"c4\n";  a=a-1; pos=pos+1; }
        else if( (s[pos]==0) && (a>0) ){ cout<<a<<" "<<b<<" "<<s[pos]<<" "<<"c5\n"; a=a-1; pos=pos+1; }
        else if( (s[pos]==0) && (a==0) ){ cout<<a<<" "<<b<<" "<<s[pos]<<" "<<"c6\n"; b=b-1; pos=pos+1; }
        else{ cout<<"c7\n";  break; }        
    }

    int ans = pos - 0 + 1; // r - l +1 that formula 
    cout<<ans<<"\n";

    if(!s)delete[] s;
    return 0;
}
