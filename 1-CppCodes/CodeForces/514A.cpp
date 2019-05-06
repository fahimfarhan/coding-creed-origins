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

    string s,t;
    cin>>s;
    int n=s.size();
    char ch;
    t = "";
    if(s[0]=='9'){  t+='9'; }
    else{
        ch = '9'-s[0]+'0';
        if(ch<s[0]){    t+=ch; }
        else{   t+=s[0];    }
    }
    for(int i=1; i<n; i++){
        ch = '9'-s[i]+'0';
        if(ch<s[i]){    t+=ch;    }
        else{   t += s[i];  }
    }

    cout<<t<<"\n";
    return 0;
}
