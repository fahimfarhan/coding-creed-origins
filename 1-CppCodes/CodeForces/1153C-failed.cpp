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

    int n; string s;

    int l, ans;
    l=0; ans=0; 
    cin>>n; cin>>s;
    // case 1: n is odd => invalid
    if( (n&1)==1 ){ cout<<":( 1"; return 0; }
    else{
        for(int i=0; i<n; i++){
            if(s[i]=='('){    l++;    }
        }
        for(int i=0; i<n; i++){
            if( (s[i]=='?') && (l<n/2)){
                s[i]='('; l++;
            }
        }
        for(int i=0; i<n; i++){
            s[i]=')';
        }

        ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){  ans++;  }
            else{
                ans--;
                if(  (ans==0) && (i!=(n))  || (ans<0) ){
                    cout<<":(2\n"; exit(0);
                }
            }
        }
        
        if(ans!=0){ cout<<s<<"\n";  }
        else{   cout<<":(3\n";  }
        
    }
    
    return 0;
}
