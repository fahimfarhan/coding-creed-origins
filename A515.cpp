#include <iostream>
#include <cstdlib>
#include <cmath>

typedef long long int ll;

using namespace std;

class A515{
private:
	ll a,b,s;
public:
	A515(){
		cin>>a>>b>>s;
		if(s<(abs(a)+abs(b))){ cout<<"NO\n"; exit(0); }
		ll d = s-abs(a)-abs(b);
		//cout<<d<<endl;
		if(d%2 == 0){ cout<<"YES\n"; }
		else{ cout<<"NO\n"; }
	}
	~A515(){}
	
};

int main()
{
	A515 a;
	return 0;
}
