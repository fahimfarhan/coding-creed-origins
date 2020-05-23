#include <bits/stdc++.h>

using namespace std;

#define N 405
double sides[N];
#define PI 2*acos(0)

int main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    
    // 1. preprocess: calc all tan theta
    double theta = 0;
    for(int i=2; i <N; i++) {
        
        sides[i] = cos(PI/(i*2)) / sin(PI/(i));
    }

    // 2. konst lookup and answer
    int T;
    int n;
    
    cin>>T;
    while(T--) {
        cin>>n;
        n = n<<1;
        cout<<sides[n]<<"\n";
    }

    return 0;
}

/*
3
3
5
199
*/