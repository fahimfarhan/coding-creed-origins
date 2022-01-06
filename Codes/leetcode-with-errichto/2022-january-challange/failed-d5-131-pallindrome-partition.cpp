#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const static int M = 17;
  const static int IS_PAL = 1;
  const static int NOT_PAL = 0;
  const static int UNKNOWN = -1;

  string input;
  int isPal[M][M];

  void preprocess() {
    for(int i = 0; i < M; i++) {
      for(int j = 0; j < M; j++) {
        isPal[i][j] = UNKNOWN;
      }
    }

    for(int i = 0; i < M; i++) {
      isPal[i][0] = IS_PAL;
      isPal[i][1] = IS_PAL;
    }
  }

  bool isPalindrome(int start, int length) {
    if(isPal[start][length] == UNKNOWN) {
      int end = start + length - 1;
      isPal[start][length] = (input[start] == input[end]) && isPalindrome(start+1, length - 2);
    }
    return isPal[start][length];
  }

  vector<string> partition(int partitionSize, int remainder, bool checkReverse) {
    vector<string> output;
    bool possible = true;
    int N = input.size();

      int iStart = 0;
      if(checkReverse) {
        if(remainder != 0) {
          int tempLen = remainder;
          int tempEnd = tempLen - 1;
          if(isPalindrome(0, tempLen)) {
            string subStr = input.substr(0, tempLen);
            output.push_back(subStr);
            iStart = remainder - 1;
          } else {
            possible = false;
          }
        }
      }

    if(possible) {    
      for(int i = iStart; i < N; i+=partitionSize) {
        int end = i + partitionSize - 1;
        if(end >= N) {
          end = N - 1;
        }
        int tempLen = end - i + 1;
        if(isPalindrome(i, tempLen)) {
          string subStr = input.substr(i, tempLen);
          output.push_back(subStr);
        } else {
          possible = false;  
          break;
        }
      }
    }    
    if(!possible) {
      output.clear();
    }
    return output;
  }

  vector<vector<string>> partition(string s) {
    this->input = s;
    preprocess();
    vector<vector<string>> output;
    int N = input.size();

    for(int i=1; i<=N; i++) { 
      vector<string> temp = partition(i, (N % i), false);
      if(!temp.empty()) {
        output.push_back(temp);
      }
      
      int remainder = N % i;
      if(remainder != 0) {
        vector<string> temp = partition(i, (N % i), true);
        if(!temp.empty()) {
          output.push_back(temp);
        }
      }
    }
    return output;
  }
};


int main() {
  string input = "cdd";
  Solution s;
  vector<vector<string>> output = s.partition(input);
  for(auto i: output) {
    cout<<"[ ";
    for(auto j: i) {
      cout<<j<<", ";
    }
    cout<<" ]\n";
  }
  return 0;
}