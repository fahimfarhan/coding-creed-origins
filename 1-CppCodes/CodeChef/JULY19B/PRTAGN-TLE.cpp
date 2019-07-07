#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

typedef int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

ll T, X, Q, y, m;
ll a[2] = {0};

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
    while(T--){
        cin>>Q;
        a[0] = 0; a[1] = 0;
        set<ll> s;
        vector<ll> temp;
        while(Q--){
            cin>>X;
            set<ll>::iterator it;
            for(it = s.begin();it!=s.end(); it++){
                y = (*it);
                y = y^X;
                temp.push_back(y);

                m = __builtin_popcount(y);
                //cout<<"y = "<<y<<" m = "<<m<<"\n";
                if((m%2)==0){ a[0]++; }
                else{   a[1]++; }
            }

            m = __builtin_popcount(X);
            //cout<<"X = "<<X<<" m = "<<m<<"\n";
            if((m%2)==0){ a[0]++; }
            else{   a[1]++; }

            for(int i=0; i<temp.size(); i++){
                s.insert(temp[i]);
            }
            temp.clear();
            s.insert(X);

            cout<<a[0]<<" "<<a[1]<<"\n";
        }
    }

    return 0;
}