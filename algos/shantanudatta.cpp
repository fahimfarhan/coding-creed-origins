#include <bits/stdc++.h>
using namespace std;

#define VAL first
#define WEIGHT second


int maxWeight = INT_MAX;

bool myComparator(const pair<int,int> &a, const pair<int,int> &b) {
  if( (a.WEIGHT <= maxWeight) && (b.WEIGHT <= maxWeight) ) {
      return (a.VAL < b.VAL);
  } else if( (a.WEIGHT > maxWeight) && (b.WEIGHT <= maxWeight)) {
    return true;
  } else if( (a.WEIGHT <= maxWeight) && (b.WEIGHT > maxWeight)) {
    return false;
  } else if( (a.WEIGHT > maxWeight) && (b.WEIGHT > maxWeight)) {
    return (a.VAL < b.VAL);
  }
  return (a.VAL < b.VAL); // kono karone uporer if else e chhara pore gele by default eita return korbe
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<pair<int,int> > input;
  int N, value, weight;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>value>>weight;
    input.push_back({value, weight});
  }

  cin>>maxWeight;

  sort(input.begin(), input.end(), myComparator);

  int len = input.size();
  int maximus = input[len-1].VAL;

  cout<<"the sorted list\n";
  for(int i=0; i<len; i++) {
   cout<<"{"<<input[i].VAL<<" "<<input[i].WEIGHT<<"} ";
  }cout<<"\n";
  cout<<"----------------------------\n-----------OUTPUT-----------\n";

  int j = len-1;
  for(int i=len-1; i>=0; i--) {
    if(input[i].VAL != maximus) {
      break;
    }
    j = i;
  }

  for(int i=j; i<len; i++) {
    cout<<"{"<<input[i].VAL<<" "<<input[i].WEIGHT<<"} ";
  }cout<<"\n";

  return 0;
}