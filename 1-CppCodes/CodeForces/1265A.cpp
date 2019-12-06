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

    int t;
    string s;
    string u = "abc";
    cin>>t;

    while(t--){
        cin>>s;
        for(int i=1; i<s.size()-1; i++){
            if(s[i]=='?'){
                for(int j=0; j<3; j++){
                    if(s[i-1]!=u[j] && s[i+1]!=u[j]){
                        s[i] = u[j]; break;
                    }
                }
            }
        }
        if(s.size() == 1 && s[0] == '?'){
            s[0] = 'a';
        }else{
            // 0th
            if(s[0]=='?') 
            for(int j=0; j<2; j++){
                if( s[1]!=u[j]){
                    s[0] = u[j]; break;
                }
            }
            // nth
            if(s[s.size()-1]=='?')
            for(int j=0; j<2; j++){
                if( s[s.size()-2]!=u[j]){
                    s[s.size()-1] = u[j]; break;
                }
            }
        }

        // check
        bool b = true;
        for(int i=0; i<s.size(); i++ ){
            if(s[i]==s[i-1]){ b=false;  break;  }
        }
        if(b){  cout<<s<<"\n";   }
        else{   cout<<"-1\n";    }
    }

    return 0;
}

