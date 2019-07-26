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

ll n,t;
map<pair<ll,ll> , ll> mp;
pair<ll,ll> *p;

void type1(){
    bool b = true;
    for(int i=1; i<n; i++){
        if( (p[i].first-p[i-1].first<=1) && p[i].second-p[i-1].second<=1 ){
            continue;
        }else{  b = false; break; }
    }
    if(b){  cout<<"YES\n";  
        for(int i=0; i<n; i++){
            cout<<mp[p[i]]<<"\n";
        }
    }
    else{
        cout<<"NO\n";
    }
}

void type2(){}

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

    cin>>n;
    cin>>t;

    p = new pair<ll,ll>[n+1];
    ll a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        p[i].first = a; p[i].second = b;
        mp[{a,b}] = (i+1);
    }
    sort(p,p+n);

    if(t==1){
        type1();
    }else if(t==2){
        type2();
    }

    delete[] p;
    return 0;
}