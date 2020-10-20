#include <bits/stdc++.h>

using namespace std;

int main() {

  int days;
  while( (cin>>days, days)!=0 ) {
    multiset<int> urn;
    int payed = 0;
    for(int i=0; i<days; i++) {
      int bills;
      cin>>bills;
      for(int j=0; j< bills; j++) {
        int temp;
        urn.insert( (cin>>temp, temp) );

        for(auto x: urn) {
          cerr<<x<<" ";
        }cerr<<"\n";
      }

      auto low = urn.begin();
      auto high = urn.end();

      high--;
      payed += (*high - *low);
      urn.erase(low);
      urn.erase(high);
    }
    cout<<payed<<"\n";
  }

  return 0;
}