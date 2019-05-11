#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

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

    ll a,b, b_a;
    cin>>a>>b;
    if(a>b){    swap(a,b);  }

    b_a = b-a;
    ll stop = sqrt(b_a)+1;
    vector<ll> s;
    for(int q=1; q<=stop; q++){
        if( (b_a%q) == 0){
            s.push_back(q); // s.insert((b_a/q));
        }
    }
    /*
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }cout<<"\n";*/

        // set<ll>::iterator it;
    ll k = 0, amodq=0,q=0, lcm0 = a*b/__gcd(a,b), lcm=lcm0;
    for(int i=0; i<s.size(); i++){
        q = s[i];
        amodq = a%q;
        if(amodq==0){
            // check for 0 and q
            /*
            ll templcm = (a+amodq)*(b+amodq)/__gcd((a+amodq),(b+amodq));
            if(templcm>lcm){
                lcm=templcm; 
                k=amodq;
            }*/
            // if(templcm == lcm){ k = 0; }
        }else{
            ll tempk = q - amodq;
            ll templcm = (a+tempk)*(b+tempk)/__gcd((a+tempk),(b+tempk));
            if(templcm > lcm){
                k = tempk;
                lcm = templcm;
            }else if(templcm == lcm){
                k = min(k,tempk);
            }
        }
    }

    // if(lcm0>lcm){   k=0;    }

    cout<<k<<"\n";  
    return 0;
}
