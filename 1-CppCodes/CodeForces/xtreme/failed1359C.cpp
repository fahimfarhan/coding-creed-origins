/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T, h,c,t, result;
    double t1, t2,t3;
    ll minimus;
    cin>>T;

    while(T--) {
        cin>>h>>c>>t;

        t1 = h;
        t2 = 1.0*(h+c)/2;

        ll n1 = 1;// = (t - h) / (h+c - 2*t);
        double dt1 = INT_MAX;
        

        for(int n=1; ; n+=2) {
            double tavg = 1.0*(n*(h+c)+h)/(2*n+1);
            double temp = abs(t - tavg);
            if(temp > dt1) {    break;  }
            dt1 = temp;
            n1 = 2*n + 1;
        }        
        t3 = dt1;

        minimus = INT_MAX;
        double dt = INT_MAX;
        if( abs(t - t1) < dt ) {
            dt = abs(t - t1);
            minimus = 1;
        }
        if( abs(t - t2) < dt ) {
            dt = abs(t - t2);
            minimus = 2;
        }

        if(abs(t - t3) < dt) {
            dt = abs(t - t2);
            minimus = n1;
        }

        cout<<minimus<<"\n";

    }


    return 0;
}

