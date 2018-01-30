#include <bits/stdc++.h>

using namespace std;

class B911
{
private:
	int n,a,b,s,d,r,ans;
public:
	B911(){
		cin>>n>>a>>b;
		d = (a+b)/n;
		r = (a+b)%n;

		s = min(a,b);

		if(s<d){ans = s;}
		else if((s%d)==0){ans = d;}
		else{ ans = s%d; }

		cout<<ans<<endl;
	}
	~B911(){}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	B911 b911;
	return 0;
}