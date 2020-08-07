#include <iostream>

using namespace std;
#define ll long long int

int main() {
    ll T,N, x,y, a, b;

    cin>>T;
    while(T--) {
        cin>>N;
        N = (N<<2)-1;

        a = a^a;
        b = b^b;
        for(int i=0; i<N; i++) {
            cin>>x>>y;
            a = a^x;
            b = b^y;
        }

        cout<<a<<" "<<b<<"\n";
    }

    return 0;
}