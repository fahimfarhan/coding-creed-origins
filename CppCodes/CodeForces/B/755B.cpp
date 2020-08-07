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
    set<string> A, B;
    vector<string> AnB;
    int n,m;
    cin>>n>>m;
    string s;
    for(int i=0; i<n; i++){ cin>>s; A.insert(s);    }
    for(int i=0; i<m; i++){ cin>>s; B.insert(s);    }
    
    set_intersection(A.begin(),A.end(),B.begin(),B.end(), back_inserter(AnB));
    
    int nA, nB, nAnB;
    nAnB = AnB.size();
    nA = n-nAnB;
    nB = m-nAnB;

    if( (nAnB&1) == 1){ nA++; }
    if(nA>nB){  cout<<"YES\n"; }
    else{       cout<<"NO\n";  }
    return 0;
}
