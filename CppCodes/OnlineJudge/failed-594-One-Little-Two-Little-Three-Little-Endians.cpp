#include <bits/stdc++.h>
#include <cstdint>
#include <ios>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int32_t input, output, bit;
    while(cin>>input) {
        output = 0;
        for(int i=0; i<31; i++) {
            bit = input & (1<<i);
            bit = bit >> i;
            bit = bit << (30 - i);
            output = output | bit;
        }
        // sign bit / 31st bit
        bit = input & (1 << 31);
        output = output | bit;
        cout<<output<<"\n";
    }

    return 0;
}