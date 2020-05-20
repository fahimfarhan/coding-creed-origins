#include <bits/stdc++.h>

using namespace std;

/**
 * My ideas:
 * 1. bruteforce (probably get TLE)
 * 2. segment tree (too big array, probably it will get ME)
 * 
 * Errichto's idea:
 * check the L&(1 << bit) == R&(1<<bit) where bit is 30 - 1. if they differ,
 * stop and return the number
 * 
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        for(int bit=30; bit>=0; bit--) {
            if(  (m & (1 << bit)) !=  (n & (1 << bit)) ) {
                break;
            }else{
                result = result | (m & (1 << bit));
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    cout<<s.rangeBitwiseAnd(5,7)<<"\n";
    cout<<s.rangeBitwiseAnd(0,1)<<"\n";
    return 0;
}