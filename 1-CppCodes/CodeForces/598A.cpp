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

    int T, N; ll n,s1,s2, sum;
    cin>>T;
    
    while(T--){
        cin>>n;
        s1 = (n+1)*n;
        s1=s1>>1;
        N = (int)log2(n)+1;
        s2 = ((1<<N)-1)<<1;

        sum = s1-s2;
        cout<<sum<<"\n";
    }

    
    return 0;
}
