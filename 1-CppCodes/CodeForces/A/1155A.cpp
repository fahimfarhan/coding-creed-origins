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

    string s;
    int n;
    cin>>n;
    cin>>s;
    n=s.size();
    bool b=false;
    int i,l,r;
    // if('a'<'b'){    cout<<"ok"; }
    for( i=n-1; i>0; i--){
        if(s[i]<s[i-1]){    b=true; break; }
    }
    if(b){  cout<<"YES\n";
        r=i+1;l=i;  
        cout<<l<<" "<<r<<"\n";
    }else{
        cout<<"NO\n";
    }

    
    return 0;
}
