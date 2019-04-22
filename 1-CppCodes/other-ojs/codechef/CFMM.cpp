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
    int T, N;
    string s;
    cin>>T;
    while(T--){
        cin>>N;
        map<char, int> mp;
        for(int i=0; i<N; i++){ 
            cin>>s;
            for(int j=0; j<s.size(); j++){  mp[s[j]]++; }
        }
        int minimus = INT_MAX;
        mp['c'] = mp['c']/2;
        mp['e'] = mp['e']/2;
        minimus = min(minimus, mp['c']);
        minimus = min(minimus, mp['d']);
        minimus = min(minimus, mp['e']);
        minimus = min(minimus, mp['f']);
        minimus = min(minimus, mp['h']);
        minimus = min(minimus, mp['o']);

        cout<<minimus<<"\n";
    }    

    
    return 0;
}
