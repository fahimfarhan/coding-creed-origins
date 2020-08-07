/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll int
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

    ll q, n, k, b, sum;
    vector<int> v;
    cin>>q;
    while(q--){
        cin>>n>>k;

        sum = 0;
        for(int i=0; i<n; i++){
            cin>>b;
            b&=1;
            sum+=b;
            if(b==1){   v.push_back(i+1);  }
        }

        if((sum<k)||( ((sum-k)%2) == 1) ){    cout<<"NO\n";       }
        else{
            cout<<"YES\n";
            for(int i=0; i<k-1; i++){
                cout<<v[i]<<" ";
            }cout<<n<<"\n";
        }

        if(!v.empty())v.clear();
    }


    return 0;
}