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

    string s,t,s1, temp;
    int acount = 0;
    cin>>t;

    for(int i=0; i<t.size(); i++){  if(t[i]=='a'){ acount++; }   }
    for(int i=0; i<t.size(); i++){
        if(acount==0){  break; }
        if(t[i]=='a'){  acount--; }
        else{   temp = temp + t[i]; }
    }

    

    
    return 0;
}
