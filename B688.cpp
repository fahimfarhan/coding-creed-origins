#include <bits/stdc++.h>

using namespace std; 

class B688{
private:
	string s;
public:
	B688()
	{
		cin>>s; 
		cout<<s; 
		reverse(s.begin(),s.end()); 
		cout<<s;
	}
	~B688(){}
};

int main()
{
	B688 a;
	return 0;
}