#include <bits/stdc++.h>

using namespace std;

class A900
{
private:
	int n, neg, pos, *x,*y;

public:
	A900(){
		neg = 0; pos = 0;
		cin>>n;
		x = new int[n];
		y = new int[n];

		for(int i=0; i<n; i++){
			cin>>x[i]>>y[i];
		}
		for(int i=0; i<n; i++){
			if(x[i]<0) neg++;	
		}
		pos = n-neg;
		if(pos==1 || neg==1 || pos==n || neg==n){ cout<<"Yes\n"; }
		else { cout<<"No\n"; }
	}
	~A900(){
		if(!x)delete[] x;
		if(!y)delete[] y;
	}
	
};

int main()
{
	A900 a;
	return 0;
}