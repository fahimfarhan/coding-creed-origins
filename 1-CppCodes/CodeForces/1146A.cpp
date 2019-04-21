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
    string s; int n;
    cin>>s;
    n = s.size();
    int acount = 0;
    for(int i=0; i<n; i++){ 
        if(s[i]=='a'){  acount++; }
    }

    if(acount>(n/2) ){
        cout<<n<<"\n";
    }else{
        n = acount<<1;
        n = n-1;
        cout<<n<<"\n";
    }

    
    return 0;
}
