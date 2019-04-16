#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


ll n,m,l,r;

stack<ll> st;
vector<ll> v;

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

    cin>>n>>l>>r;
    st.push(n);
    ll first_last, mid;
    while(!st.empty()){
        n=st.top();
        st.pop();
        if(n>1){
            first_last=(n>>1);
            mid = (n&1);
            st.push(first_last); st.push(mid); st.push(first_last);
        }else{
            v.push_back(n);
        }
    }

    ll ans = 0;
    n=v.size();
    l--; r--;
    for(int i=l; i<=r; i++){
        ans+=v[i];
    }    
    cout<<ans<<"\n";
    return 0;
}
