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

    map<char, string> mp[2];

    mp[0]['1'] = "a";
    mp[0]['2'] = "bb";
    mp[0]['3'] = "ab";

    mp[1]['1'] = "b";
    mp[1]['2'] = "aa";
    mp[1]['3'] = "ba";

    int m = 0;

    ll N;
    string s, out;
    cin>>N;
    cin>>s;


    int fourCount = 0;
    for(int i=0; i<N; i++){ if(s[i]=='4'){  fourCount++;    }}
    m = fourCount%2;

    out = "";
    for(int i=0; i<N; i++){
        if(s[i]=='4'){  m = (m+1)%2;    }
        else{
            out=out+mp[m][s[i]];
        }
    }

    cout<<out<<"\n";

    return 0;
}