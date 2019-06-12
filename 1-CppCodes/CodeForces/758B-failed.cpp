#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define R 0
#define B 1
#define Y 2
#define G 3

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

int k[4] = {0,0,0,0};
string s;

map< char, int > mp;

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

    cin>>s;

    mp['R'] = R;
    mp['B'] = B;
    mp['Y'] = Y;
    mp['G'] = G;
    
    for(int i=3; i<s.size(); i+=4){
        bool mark[4] = {0,0,0,0};
        
        for(int j=i-3; j<=i; j++){
            if(s[j]!='!'){
                char ch = s[j];
                mark[mp[ch]] = 1;
            }
        }

        for(int j=0; j<4; j++){
            if(!mark[j]){   k[j]++;   }
        }
    }

    if(s.size()%4!=0){
        int i = s.size()-1;
        bool mark[4] = {0,0,0,0};
        
        for(int j=i-3; j<=i; j++){
            if(s[j]!='!'){
                char ch = s[j];
                mark[mp[ch]] = 1;
            }
        }

        for(int j=0; j<4; j++){
            if(!mark[j]){   k[j]++;   }
        }
    }

    for(int i=0; i<4; i++){ cout<<k[i]<<" ";    }cout<<"\n";
    return 0;
}
