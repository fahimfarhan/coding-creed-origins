#include <bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int> > group;
    int maxFreq = 0;
    FreqStack() {
      maxFreq = 0;
    }

    int getFrequencyOrDefault(const int& input, const int& defaultValue) {
      auto output = freq.find(input);
      if( output == freq.end() ) {
        return defaultValue;
      }
      return output->second;
    }

    void computeIfAbsentAndPush(const int& val, const int& freq) {
      auto p = group.find(freq);
      if( p == group.end() ) {
        stack<int> temp;
        temp.push(val);
        group[freq] = temp;
      } else {
        p->second.push(val);
      }
    }

    void push(int val) {
        int oldf = getFrequencyOrDefault(val, 0);
        int newf = oldf+1;
        freq[val] = newf;
        
        if(newf > maxFreq) {
          maxFreq = newf;
        }
        computeIfAbsentAndPush(val, newf);
    }
    
    int pop() {
      int x = group[maxFreq].top();
      group[maxFreq].pop();

      freq[x] = freq[x] - 1;
      if(group[maxFreq].size() == 0) {
        maxFreq--;
      }
      return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
  

  return 0;
}
