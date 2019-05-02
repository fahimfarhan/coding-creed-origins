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

    ll n,k;
    map<char,ll> mp;
    string s;
    
    cin>>n>>k;
    cin>>s;
    for(int i=0; i<n; i++){ mp[s[i]]++; }

    ll *v; v = new ll[mp.size()+1];
    map<char,ll>::iterator it;

    int j=0;
    for(it=mp.begin(); it!=mp.end(); it++){
        v[j]=it->second;
        j++;
    }
    sort(v, v+j);
    ll temp=0, ans=0;
    for(int i=j-1; i>=0; i--){
        // temp = min(v[i],k);
        if(v[i]<k){ temp=v[i];  }else{  temp=k; }
        k = k-temp;
        ans=ans+temp*temp;
        if(k==0){   break; }
    }

    cout<<ans<<"\n";
    delete[] v;
    return 0;
}
