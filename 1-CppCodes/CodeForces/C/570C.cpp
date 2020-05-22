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

    int n,q; 
    char ch,*a;
    cin>>n>>q;
    a = new char[n+2];

    for(int i=1; i<=n; i++){    cin>>a[i]; }
    a[0]='7'; a[n+1]='7';

    int ans = 0;
    for(int i=1; i<=n; i++){
        if( (a[i-1]=='.') && (a[i]=='.') ){ ans++; }
    }

    while(q--){
        cin>>n>>ch;
        if( (ch == '.') && (a[n]!='.') ){
            ans+=(a[n-1]=='.');
            ans+=(a[n+1]=='.');
        }

        else if( (ch != '.') && (a[n]=='.') ){
            ans-=(a[n]==a[n-1]);
            ans-=(a[n]==a[n+1]);
        }

        a[n]=ch;
        cout<<ans<<"\n";
    }

    if(!a)delete[] a;
    return 0;
}
