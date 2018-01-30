#include <iostream>
#include <cstring>

using namespace std;

class A735{
public:
  int n, k;
  string s;
    bool b;
A735(){
    b = true;
  //scanf("%d %d",&n,&k);
  cin>>n>>k>>s;
  int x = s.find('G');
  int y = s.find('T');
  if(x>y){    x = x^y; y=x^y; x=x^y;  }
  for(int i=x; i<y; i+=k){
    if(s[i]=='#'){
      cout<<"NO\n";
      b = false; break;
    }
  }
  if(b)cout<<"YES\n";
}
~A735(){}

};

int main()
{
    A735 a;
  return 0;
}
