#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,stop, mygcd ,a=0,b=0,  amax=0, bmax=0;
    
    double temp, maximus;
    temp=0.0;
    maximus = 0.0;
    cin>>n;
    stop = (int)n/2;
    if(stop == (n-stop)){   stop--; }
    for(int i=1; i<=stop; i++){
        a=i; b = n-i;
        temp = (a*1.0)/b;
        //cout<<a<<" "<<b<<" "<<temp<<" "<<maximus<<"\n";
        mygcd = __gcd(a,b);
    
        if( (mygcd==1) &&  (temp > maximus) ){ maximus = temp; amax = a; bmax=b; }
    }
    
    cout<<amax<<" "<<bmax<<"\n"; 
    return 0;
}