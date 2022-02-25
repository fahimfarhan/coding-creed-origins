#include <bits/stdc++.h>
using namespace std;

inline vector<string> split(const string& input,const string& regex) {
  vector<string> output;

  int start = 0, end = 0, end1 = 0, size = 0;
  while(true) {
    end = input.find(regex, start);
    if(end == -1) {
      string subString = input.substr(start);
      output.push_back(subString);
      break;
    }
    end1 = end - 1; // excluding dot
    size = end1 - start + 1;
    /*
    input = "100.0.0", start = 0, end = 4 (1st dot position), we want s[0..3] = 100, so end1 = end-1
    */
    string subString = input.substr(start, size);
    output.push_back(subString);

    start = end + regex.size();
  }

  return output;
}

void printer(vector<string> input) {
  for(auto s: input) {
    cerr<<s<<" ";
  } cerr<<"\n---------\n";
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
      vector<string> v1 = split(version1, ".");
      vector<string> v2 = split(version2, ".");

      // printer(v1);
      // printer(v2);
      int ret = 0;

      int delta = v1.size() - v2.size();

      if(delta > 0) {
        for(int i=0; i<delta; i++) {
          v2.push_back("0");
        }
      } else if(delta < 0) {
        delta = -delta;
        for(int i=0; i<delta; i++) {
          v1.push_back("0");
        }
      }

      // int minimus = min(v1.size(), v2.size());
      int size = v1.size();
      for(int i=0; i<size; i++) {
        string v1i = v1[i];
        string v2i = v2[i];

        ret = comparator(v1i, v2i);

        if(ret != 0) {  break;  }
      }
      return ret;
    }

    int comparator(string v1, string v2) {
      int v1size = v1.size();
      int v2size = v2.size();

      int delta = v1size - v2size;

      if(delta > 0) {
        for(int i=0; i< delta; i++) {
          v2 = "0" + v2;
        }
      } else if(delta < 0) {
        delta = -delta;
        for(int i=0; i< delta; i++) {
          v1 = "0" + v1;
        }
      }

      int size = v1.size();
      for(int i=0; i<size; i++) {
        if(v1[i] > v2[i]) {
          return 1;
        } else if(v1[i] < v2[i]) {
          return -1;
        }
      }
      return 0;
    }
};

int main() {
  Solution s;
  cout<<s.compareVersion("192.168.0.1", "8.8.8.8")<<"\n";
  
  return 0;
}