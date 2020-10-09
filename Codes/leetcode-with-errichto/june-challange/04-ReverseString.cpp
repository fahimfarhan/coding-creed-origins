#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0; i<n/2; i++) {
            swap(s[i], s[n-1-i]);
        }      
    }
};

int main() {

    return 0;
}