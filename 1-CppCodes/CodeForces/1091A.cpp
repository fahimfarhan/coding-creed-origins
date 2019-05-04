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

    int Y,R,B,maximus=INT_MIN, s;
    cin>>Y>>B>>R;

    int y,b,r;
    y=Y; b=y+1; r=b+1;
    if( (b<=B) && (r<=R) ){ s = y+b+r; maximus = max(s,maximus); }

    b=B; r=b+1; y=b-1;
    if( (y<=Y) && (r<=R) ){ s = y+b+r; maximus = max(s,maximus); }

    r=R; b=r-1; y=b-1;
    if( (b<=B) && (y<=Y) ){ s = y+b+r; maximus = max(s,maximus); }

    cout<<maximus<<"\n";
    return 0;
}
