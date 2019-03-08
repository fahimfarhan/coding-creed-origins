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
    /* Soln soln */
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
    cin>>s;

    // find the left most 0
    int index=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){ index=i; break;   }
    }

    for(int i=0; i<index; i++){ cout<<s[i]; }
    for(int i=index+1; i<s.size(); i++){    cout<<s[i]; }
    cout<<"\n";

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/