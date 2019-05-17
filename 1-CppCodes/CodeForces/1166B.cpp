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

    int n,m,k;
    bool b = false; 
    cin>>k;

    for(int i=5; i*i <=k; i++){
        if((k%i)==0){
            n = i; m = k/n;
            if((n>=5) && (m>=5)){
                b = true; break;
            }
        }
    }

    if(!b){
        cout<<"-1\n";
    }else{
        string t, s = "aeiou";
        for(int i=0; i<(n-5); i++){
            s = s+'x';
        }

        for(int i=0; i<m; i++){
            cout<<s;
            t = "";
            t = s.substr(1);
            t = t + s[0];
            s = "";
            s = t;
        }cout<<"\n";
    }
    return 0;
}
