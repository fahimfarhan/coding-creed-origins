#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m,a,b;
set< pair<int,int> > s;

vector<int> *g;
bool *isvisited;

bool f(int k){
    if(k==n){   return false;   }
    pair<int,int> t;
    set<pair<int,int> >::iterator it;
    int f,s1;
    for(it=s.begin(); it!=s.end(); it++){
        f = it->first; s1 = it->second;
        f+=k; s1+=k;
        if(f>n){   f = f%n;    }
        if(s1>n){ s1 = s1%n;  }

        if(f>s1){    swap(f,s1);  }
        t.first=f; t.second = s1;

        if(s.find(t)==s.end()){    return false;   }

    }
    return true;
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

    cin>>n>>m;
    for(int i=0; i<m; i++){ cin>>a>>b; if(a>b){ swap(a,b);  } s.insert({a,b});   }

    for(int i=1; i<=sqrt(n)+1; i++){
        if( (n%i)==0){
            if(f(i)){
                cout<<"Yes\n";  return 0;
            }
            if( f(n/i) ){
                cout<<"Yes\n";  return 0;
            } 
        }
    }
    cout<<"No\n";
    return 0;
}
