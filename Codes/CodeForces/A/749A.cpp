#include <iostream>
#include <cstdlib>

typedef long long int ll;

using namespace std;

class A749{
private:
  ll n, k, d;
public:
  A749(){
    cin>>n;
    cout<<n/2<<endl;
	while(n>3){
		cout<<2<<" ";
		n-=2;
	}
	cout<<n;
  }
  ~A749(){}
};

int main()
{
    A749 a;
    return 0;
}
