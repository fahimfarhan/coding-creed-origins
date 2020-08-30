/** @brief:
*          https://acmproblemsolver.wordpress.com/2012/04/23/solution-of-acm-uva-594/
*          11111111 00000000 10101010 01010101
*          becomes
*          01010101 10101010 00000000 11111111
*/

#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int n = 123456789;
    // int m = 365779719;

    int n, m;
    while(cin>>n) {

        bitset<32> input(n);

        string inputString = input.to_string();
        string outputString = "";
        
        for(int i=0; i<32; i+=8) {
            string byte = "";
            for(int j=i; j<i+8; j++) {
                byte = byte + inputString[j];
            }
            outputString =  byte + outputString;
        }

        bitset<32> output(outputString);
        // cout<<output.to_ulong()<<"\n";
        m = output.to_ulong();
        cout<<n<<" converts to "<<m<<"\n";
    }

    
    return 0;
}