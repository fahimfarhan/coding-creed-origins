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

    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int a[26] = {0};

        sort(s.begin(), s.end());
        // cout<<s<<"\n";
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a']++;
        }
        bool flag=true;
        for(int i=01; i<s.size(); i++){
            if(s[i] - s[i-1] != 1 ){    flag = false; break;  }
        }
        if(flag){
            for(int i=0; i<26; i++){
                if(a[i]>1){ flag = false; break; }
            }
        }
        
        if(flag){   cout<<"Yes\n";   }
        else{       cout<<"No\n" ;   }
    }

    return 0;
}
