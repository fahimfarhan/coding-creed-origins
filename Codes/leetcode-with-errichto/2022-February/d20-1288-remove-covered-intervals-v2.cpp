#include <bits/stdc++.h>
using namespace std;

inline bool comparator(const vector<int>& a, const vector<int>& b) {
  if(a[0] == b[0]) {
    return b[1] <= a[1];
  }
  return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
      int remainingCount = 0;
      int end = -1;
      int deleteCount = 0;
      int N = intervals.size();

      sort(intervals.begin(), intervals.end(), comparator);

      for(auto interval: intervals) {
        if(end < interval[1]) {
          end = interval[1];
        } else {
          deleteCount++;
        }
      }
      
      remainingCount = N - deleteCount;
      return remainingCount;
    }
};


int main() {

  return 0;
}