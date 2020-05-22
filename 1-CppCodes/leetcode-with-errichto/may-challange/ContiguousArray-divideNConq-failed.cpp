#include <bits/stdc++.h>
using namespace std;
/**
 * @brief: I was thinking more of a divide n conq approach. didnt work... :/ idk why...
 * 
 * 
*/
class Solution {
private: 
    vector<int> nums;
public:
    int divideAndConquer(int l, int r) {
        int len = r - l +1;
        // the impossible cases
        if(len < 2) {   return 0; }
        if(l > r ) {    return 0; } // most probably we dont need it....

        if(len == 2) { // the base case  
            return ((nums[l]^nums[r])*2);
        }

        int m = len>>1;

        int left = findMaxOnLeft(l, m);
        int right = findMaxOnRight((m+1), r);
        int mid = findMaxInMiddle(l, r, m);

        return max( max(left, right), mid);
    }

    int findMaxOnRight( int l, int r) {    return divideAndConquer(l, r);   }

    int findMaxOnLeft ( int l, int r) {    return divideAndConquer(l, r);   }

    int findMaxInMiddle( int l, int r, int m) {
        int p1 = m; int p2 = m+1;
        int kountLeft=0, kountRight=0;

        bool bleft = true, bright = true;
        while( (p1>l) && (p2<r) && (bleft|bright) ) {
            if( (nums[p1]^nums[p1-1]) && bleft)  {   kountLeft++; }else{ bleft = false;  }
            if( (nums[p2]^nums[p2+1]) && bright) {   kountRight++;}else{ bright = false;  }

            p1-=2; p2+=2;
        }

        int kount = kountLeft + kountRight;
        kount = kount<<1;

        return kount;
    }

    int findMaxLength( vector<int> nums ) {
        this->nums = nums;
        // there can be 3 cases: 1. leftHalf,OR 2. rightHalf, OR 3. Middle
        int l = 0, r = nums.size()-1, m = (r - l + 1)>>1;
        int left = findMaxOnLeft( 0, m);
        int right = findMaxOnRight( m+1, r);
        int mid = findMaxInMiddle( l, r, m);
 
        return max( max(left, right), mid);
    }
};


int main() {
    vector<int> v = {0,1,1,0,1,1,1,0};
    Solution s;
    cout<<s.findMaxLength(v);
    return 0;
}