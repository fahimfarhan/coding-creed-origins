#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class A9{
private:
  int y,w;
public:
  A9(){
    cin>>y>>w;
    if(w>y){ y = w; }
    w = 0;
    for(int i=y; i<=6; i++){
      w++;
    }


      int gcd = __gcd(w,6);
      cout<<(w/gcd)<<"/"<<(6/gcd)<<"\n";


  }
  ~A9(){}

};

int main()
{
  A9 a;
  return 0;
}
