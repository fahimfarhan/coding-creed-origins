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

    int n,t,c,a,b, curr;
    a=0; b=0; c=0; curr=0;
    cin>>n>>t>>c;
    for(int i=0; i<n; i++){
      cin>>curr;
      if(curr>t){ a = 0; }
      else{
        a++;
        if(a>=c){ b++; }
      }
    }

    cout<<b<<"\n";
    return 0;
}
