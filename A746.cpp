#include <iostream>
#include <cstdlib>

typedef long long int ll;

using namespace std;

class A746{
private:
	ll a,b,c,d; 
public:
	A746();
	~A746(){	}
};

A746::A746(){
	d = 0;
	cin>>a>>b>>c;
	b = b/2;
	c = c/4;
	if(a<b){	d = a;	}
	else{ d = b;	}
	
	if(c<d){ d = c;	}
	d = 7*d;
	cout<<d;
	//cout<<a<<b<<c;
}

int main()
{
	A746 *a = new A746();
	
	delete a;
	return 0;
}



