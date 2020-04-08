#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n){
        int r = 0, m = 0;
        while(n){
            r = n%10;
            n = n/10;
            m = m+r*r; 
        }
        return m;
    }

    bool isHappy(int n) {
        unordered_set<int> isvisited;
        int m=n;
        while(true){
            if(m == 1){
                return true;
            }
            m = f(m);
            if(isvisited.count(m)==1){
                return false;
            }
            isvisited.insert(m);
        }
    }
};

int main(){
    Solution s;
    cout<<s.isHappy(69)<<"\n";
    cout<<s.isHappy(19)<<"\n";
    return 0;
}