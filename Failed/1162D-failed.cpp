#include <bits/stdc++.h>
using namespace std;
#define MODULO 1e9+7
#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);

vector<int> *g;
bool *isvisited;

int n,m,a,b;
set< pair<int,int> > s;

bool f(int k){
    
    set< pair<int,int> >::iterator it;
    for(it = s.begin();  it!=s.end(); it++){
        pair<int,int> t;

        t.first = ((it->first)+k); t.second = ((it->second) + k);
        if(t.first>n){ t.first=t.first%n;  }
        if(t.second>n){ t.second=t.second%n;  }

        if(t.first > t.second ){
            int temp = t.first; 
            t.first = t.second;
            t.second = temp;
        }
        if(s.find(t)==s.end()){ return false;   }  
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
    vector<int> v;

    for(int i=1; i<(int)sqrt(n)+1; i++){
        if( (n%i)==0 ){    v.push_back(i);    }
    }

    for(int i=0; i<m; i++){
        cin>>a>>b;
        if(a>b){    a=a^b; b=a^b; a=a^b; }
        s.insert({a,b});
    }

    bool ans = false;

    int k=0, l=v.size(); 
    for(int i=0; i<l; i++){
        k = v[i];
        ans = f(k);
        if(ans){    break;  }
    }

    if(ans){    cout<<"Yes\n";   }
    else{       cout<<"No\n" ;   }

    //delete[] a; delete[] b;
    return 0;
}
