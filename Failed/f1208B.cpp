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

    ll n, *a;
    map<ll,bool> mp;
    
    cin>>n;
    a = new ll[n+1];

    for(int i=0; i<n; i++){ cin>>a[i];  }



    int count = 0;
    int countLeft = 0;
    int countRight = 0;

    for(int i=0; i<n; i++){
        if(!mp[a[i]]){ mp[a[i]]=true; count++;  }
        else {   break;    }
    }
    countLeft = count;
    if(count == n){  cout<<(n-count)<<"\n";  exit(0);    }
    
    // mp.clear();
    
    for(int i=n-1; i>0; i--){
        if(!mp[a[i]]){ mp[a[i]]=true; count++;   }
        else{   break; }
    }

    mp.clear();
    for(int i=n-1; i>0; i--){
        if(!mp[a[i]]){ mp[a[i]]=true; countRight++;   }
        else{   break; }
    }

    ll res = n-count;
    
    // cout<<res<<" "<<prefix<<" "<<prefixLen<<" "<<suffix<<" "<<suffixLen<<"\n";
    cout<<res<<"\n";
    delete[] a;
    return 0;
}