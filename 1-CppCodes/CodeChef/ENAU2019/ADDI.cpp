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

        ll T, N;
        ll lsb=0;
        ll count = 0;
        cin>>T;
    while(T--){
        count = 0; lsb = 0; N = 0;
        cin>>N;
        ll j = 1;
        ll temp = 1;
        while(temp<=N){  lsb++; temp=temp<<1;    }
        for(int i=0; i<32; i++){
            j = j<<i;
            if(j>N){   //lsb = i;  
                break; 
            }
            if( (N&j) == j){    count++;  }
        }
        ll result = lsb - count;
        //cout<<lsb<<" "<<count<<" "<<result<<"\n";
        cout<<result<<"\n";
    }


    return 0;
}