#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;

        int n = s.size();
        int m = t.size();

        i = n - 1;
        j = m - 1;
        while(i>=0 && j >=0) {
            if(s[i] == t[j]) {
                i--;
                j--;
            }else{
                j--;
            }
        }

        return (i == -1);
    }
};

int main() {
    Solution s;
    cout<<s.isSubsequence("abc", "ahbgdc")<<"\n";
    cout<<s.isSubsequence("axc", "ahbgdc")<<"\n";
    return 0;    
}