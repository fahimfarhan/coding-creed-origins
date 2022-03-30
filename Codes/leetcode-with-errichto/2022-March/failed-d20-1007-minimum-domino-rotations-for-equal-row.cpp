#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
      unordered_map<int, int> mpNumToCount;

      int N = tops.size();
      int maximusKey = INT_MIN;
      int maximus = INT_MIN;

      for(int i=0; i<N; i++) {
        if(tops[i] == bottoms[i]) {
          mpNumToCount[ tops[i] ]++;
        } else { 
          mpNumToCount[ tops[i] ]++;
          mpNumToCount[ bottoms[i] ]++;
        }

        int key = tops[i];
        int value = mpNumToCount[key];
        if(value > maximus) {
          maximusKey = key;
          maximus = value; 
        }

        key = bottoms[i];
        value = mpNumToCount[key];
        if(value > maximus) {
          maximusKey = key;
          maximus = value; 
        }
      }


      if(maximus < N) {
        return -1; // impossible
      } else {
        int kount = 0;
        for(int i=0; i<N; i++) {
          if(tops[i] != maximus) {
            kount++;
          }
        }

        kount = min(kount, (N - kount));

        return kount;
      }
      return 0;
    }
};

int main() {
    
    return 0;
}
