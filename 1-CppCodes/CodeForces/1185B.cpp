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
    string s,t;

    cin>>n;

    int i,j;
    bool b;
    while(n--){
        cin>>s;
        cin>>t;

        if(s.size() > t.size() ){    cout<<"NO\n";   }
        
        else{
            b = true;
            i=0; j=0;
            while(true){
                //cout<<i<<" "<<j<<"\n";
                if( (i == s.size()) ){ break; }
                if( s[i] == t[j] ){
                    i++;
                    j++;
                    //cout<<"After i++ j++ : "<<i<<" "<<j<<"\n";
                }
                else if(t[j]==t[j-1]){
                    j++;
                    
                }else{
                    //cout<<"tj : "<<t[j]<<" "<<t[j-1]<<"\n";
                    //cout<<"here2\n";
                    b = false; 
                    break;
                }
            
            }

            if(i<s.size()){ b = false; }
            else if(j<t.size()){
                // cout<<"lol\n"<<j+1<<" "<<t.size()<<"\n";
                    for(int k = j; k<t.size(); k++){
                        if(t[k]!=t[k-1]){   b = false; break; }
                }    
                
            }

            if(b){  cout<<"YES\n";  }
            else{   cout<<"NO\n";   }

        }
        // -----------
    }

    return 0;
}
