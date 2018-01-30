#include <bits/stdc++.h>

using namespace std; 

class M883{
private:
	int x1, y1, x2, y2, l, h, ans;
public:
	M883(){
		cin>>x1>>y1;
		cin>>x2>>y2;

		l = abs(x1-x2)+1;
		if(x1==x2){l++; }
		h = abs(y1-y2)+1;
		if(y1==y2){h++; }
		ans = 2*(l+h);

		cout<<ans<<endl;
	}

};

int main()
{
	M883 ob;
	return 0;
}