#include <bits/stdc++.h>
using namespace std;
/**
 * ektu ektu bujhsi, kintu onno kono similar problem e hoyto etar kotha mone porbe na
 * 
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) {
            return -1;
        }
        int low = 0, high = n-1;
        int first = nums[0];
        while(low <= high) {
            int mid = low + (high - low)/2;
            int value = nums[mid];

            if(value == target) {   return mid; }

            bool amBig = (value >= first);
            bool targetBig = (target >= first);

            if(amBig == targetBig) {
                if(value < target) {
                    low = mid+1;
                }else{
                    high = mid-1;
                } 
            }else {
                if(amBig) {
                    low = mid + 1;
                }else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}