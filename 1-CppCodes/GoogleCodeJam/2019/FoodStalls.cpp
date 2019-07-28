/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

#define x first
#define c second
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

ll T,N,  K, minimus;

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

    cin>>T;
    for(int t=1; t<=T; t++){
        minimus = INT_MAX;
        cin>>K>>N;
        K = K+1;
        vector< pair<ll,ll> > v(N);

        for(int i=0; i<N; i++){ cin>>v[i].x;    }
        for(int i=0; i<N; i++){ cin>>v[i].c;    }
        
        sort(v.begin(),v.end());

        ll sum[N]={0};  
        // for(int i=0; i<N; i++){ sum[i] = v[i].x + v[i].c;   }
        for(int j=0; j<N; j++){
            
            for(int i=0; i<N; i++){
                sum[i]= v[i].c+ abs(v[i].x-v[j].x);
            }

            sort(sum,sum+N);
            ll temp1 = 0;
            for(int i=0; i<K; i++){ temp1+=sum[i];   }
            minimus = min(minimus, temp1);
        }

        cout<<"Case #"<<t<<": "<<minimus<<"\n";

    }



    return 0;
}