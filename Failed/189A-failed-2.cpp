#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a[3];
    cin>>n>>a[0]>>a[1]>>a[2];

    sort(a,a+3);    // so a0]->small, a1 med a2 big
    int lcm_ab, lcm_ac;

    lcm_ab = (a[0]*a[1])/__gcd(a[0],a[1]);
    lcm_ac = (a[0]*a[2])/__gcd(a[0],a[2]);

    int count = 0;

    if(lcm_ab<lcm_ac){
        count = (n - lcm_ab)/a[0] + lcm_ab/a[1];
    }else{
        count = (n - lcm_ac)/a[0] + lcm_ab/a[2];
    }

    cout<<count<<"\n";
    return 0;
}