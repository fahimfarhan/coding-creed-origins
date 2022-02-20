#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int>& a, vector<int>& b) {
  if(a[0] == b[0]) {
    return a[1] > b[1];
  }
  return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), comparator);      
    
      int N = intervals.size();
    
      int end = -1;
      int deleteCount = 0;
      for(auto interval: intervals) {
        if(interval[1] > end) {
          end = interval[1];
        } else {
          deleteCount++;
        }
      }
      int remainingCount = N - deleteCount;
      return remainingCount;
    }
};

int main() {


  return 0;
}