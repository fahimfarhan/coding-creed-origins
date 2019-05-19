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

int n,m,k;
    string *s;

// int n,m;
vector<int> *g;
bool *isvisited;

bool isvalid(int i, int j){
    if( (i>=0 && i<n) && (j>=0 && j<m) ){   return true;    }
    return false;
}


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

    
    cin>>n>>m>>k;
    s = new string[n];

    for(int i=0; i<n; i++){    cin>>s[i];  }

    int degree=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            degree = 0;
            if(s[i][j]=='#'){   continue;   }
            if(isvalid((i+1), j) ){
                if(s[i+1][j]=='.'){ degree++; }
            }            
            if(isvalid((i-1), j) ){
                if(s[i-1][j]=='.'){ degree++; }
            }
            if(isvalid((i),(j+1) ) ){
                if(s[i][j+1]=='.'){ degree++; }
            }
            if(isvalid((i), (j-1)) ){
                if(s[i][j-1]=='.'){ degree++; }
            }

            if( (degree==1) && (k>0)){  s[i][j]='X'; k--;    }
            if(k==0){   break;  }
        }
    }

    for(int i=0; i<n; i++){ cout<<s[i]<<"\n";   }
    delete[] s;

    return 0;
}
