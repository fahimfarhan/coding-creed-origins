#include <bits/stdc++.h>

using namespace std;

#define N 405
double tangents[N];
#define PI 2*acos(0)

int main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    
    // 1. preprocess: calc all tan theta
    for(int i=2; i <N; i+=2) {
        tangents[i] = 1.0 / tan(PI/i);
    }

    // 2. konst lookup and answer
    int T;
    int n;
    
    cin>>T;
    while(T--) {
        cin>>n;
        n = n<<1;

        cout<<tangents[n]<<"\n";
    }

    return 0;
}