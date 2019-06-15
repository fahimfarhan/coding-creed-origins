#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
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

    int T,N, numOfBs, numOfDots;
    string s;
    cin>>T;

    for(int t=1; t<=T; t++){
        cin>>s;

        numOfBs = 0; numOfDots = 0;
        
        N = s.size();
        for(int i=1; i<N; i++){
            if(s[i] == 'B'){    numOfBs++; }
            else if(s[i] == '.'){   numOfDots++; }
        }

        if( (numOfDots!=0) && (numOfBs!=0) && (numOfBs>=numOfDots) ){
            cout<<"Case #"<<t<<": Y\n";
        }else{ cout<<"Case #"<<t<<": N\n"; }

    }

    return 0;
}
