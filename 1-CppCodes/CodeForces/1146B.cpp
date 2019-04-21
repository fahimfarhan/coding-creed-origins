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
    string s1, s2, t;
    cin>>t;
    for(int i=0; i<t.size(); i++){
        s1+=t[i];
        if(t[i]!='a') s2+=t[i];
        if(s1.size()+s2.size()==t.size()) break;
    }
    if(t==s1+s2) cout<<s1<<endl;
    else cout<<":(\n";
    return 0;
    
    
}
