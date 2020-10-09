#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t end = 4000000;
    int64_t a,b, c;
    a=1,b=2;
    int64_t sum = 0;

    while(b<end){
        if(b%2 == 0){   sum+=b; }
        c = b;
        b+=a;
        a = c;
    }

    cout<<sum<<"\n";

    return 0;
}