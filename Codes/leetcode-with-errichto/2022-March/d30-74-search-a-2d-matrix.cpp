#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numberOfRows = matrix.size();
        int numberOfColumns = matrix[0].size();

        int start = 0;
        int end = numberOfRows*numberOfColumns - 1;

        if(target == matrix[0][0]) {
          return true;
        }

        if(target == matrix[numberOfRows-1][numberOfColumns-1]) {
          return true;
        }

        int mid = start + ((end - start) >> 1);
        int r, c;
        while (start < end) {
          cerr<<"start = "<<start<<", mid = "<<mid<<", end = "<<end<<"\n";
          /* code */
          mid = start + ((end - start) >> 1);
          r = getRow(mid, numberOfColumns);
          c = mid - r * numberOfColumns;

          if(target == matrix[r][c]) {
            return true;
          } else if(target < matrix[r][c]) {
            end = mid;
          } else {
            start = mid+1;
          }
        }
        return false;
    }

    int getRow(const int& input, const int& numberOfColumns) {
      return (input / numberOfColumns);
    }

};

int main () {
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]

  vector<int> v1 = {1,3,5,7};
  vector<int> v2 = {10,11,16,20};
  vector<int> v3 = {23,30,34,60};
  
  vector<vector<int>> v = {v1, v2, v3};

  Solution s;

  cout<<s.searchMatrix(v, 3)<<"\n";
  cout<<s.searchMatrix(v, 13)<<"\n";

  return 0;
}