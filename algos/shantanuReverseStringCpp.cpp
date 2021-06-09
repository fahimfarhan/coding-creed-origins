#include <bits/stdc++.h>
using namespace std;

string reverseWords(const string& input) {
  string output = "";

  string word = "";
  int N = input.size();
  for(int i=0; i<N; i++) {
    if(input[i] == ' ') {
      output = word + " " + output;
      word = "";
    }else{
      word = word + input[i];
    }
  }
  if(word.size() > 0) { 
    output = word + " " + output;
  }
  return output;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string input = "i like this program very much";
  string output = reverseWords(input);
  cout<<output<<"\n";
  return 0;
}