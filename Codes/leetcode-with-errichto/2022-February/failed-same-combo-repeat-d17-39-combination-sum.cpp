#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  unordered_set<priority_queue<int>*> result;

  void combination(vector<int>& candidates, int target, priority_queue<int>& subList) {
    if(target == 0) {
      result.insert(&subList);
    } else if(target < 0) {
      return;
    } else {
      for(auto i: candidates) {
        priority_queue<int> tempSubList = subList;
        tempSubList.push(i);
        int tempTarget = target - i;
        combination(candidates, tempTarget, tempSubList);
      }
    }
  }


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        priority_queue<int> emptyList;
      combination(candidates, target, emptyList);
      
      vector<vector<int>> output;
      for(auto pq1: result) {
        priority_queue<int> pq = *pq1;
        vector<int> temp;
        while (!pq.empty()){
          /* code */
          int top = pq.top();
          pq.pop();
          temp.push_back(top);
        }
        output.push_back(temp);
      }
      return output;       
    }
};

int main() {

  return 0;
}