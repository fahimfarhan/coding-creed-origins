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

    vector<int> preprocess[15];
    for(int i=1; i<=10; i++){
        for(int j=i; j<=10*i; j+=i){
            preprocess[i].push_back( (j%10) );
        }
    }

    vector<int> cf[15]; 
    for(int i=1; i<=10; i++){
        cf[i].push_back(preprocess[i][0]);
        for(int j=1; j<preprocess[i].size(); j++){
            int temp = preprocess[i][j]+preprocess[i][j-1];
            cf[i].push_back(temp);
        }
    }

    ll res, a,b,c,d,q, n, m, zero=0;

    cin>>q;
    while(q--){
        cin>>n>>m;
        a = n/m;
        b = a/10; 
        c = a%10;
        d = m%10;

        if((d == zero) || (m>n) ){
            cout<<0<<"\n";
        }else{
            ll temp = cf[d].size()-1;
            res = b*cf[d][temp];
            res += cf[d][c];
            cout<<res<<"\n";
        }
    }



    return 0;
}