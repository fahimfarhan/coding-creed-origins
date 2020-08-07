/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
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

    ll N, M, L, T;
    bool b=true;
    T = 0;

    cin>>N>>M;
    if(N*M>60){ b = false; }
    else{
        for(int i=0; i<N; i++){
            cin>>L;
            if(L<M){    b = false; }
            else{   if(b) T+=M; }
        }
    }

    if( (b==true) && (T==60)){   cout<<"YES\n";  }
    else{   cout<<"NO\n";   }


    return 0;
}