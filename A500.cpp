#include <bits/stdc++.h>

using namespace std;

class A500
{
private:
	int n,t, *cell;

public:
	A500(){
		cin>>n>>t;
		cell = new int[n+1];
		for(int i=1; i<n; i++){ cin>>cell[i];}
		bool b = Algorithm();
		if(b) cout<<"YES\n";
		else cout<<"NO\n";	
	}
	bool Algorithm(){
		int i=1;
		bool b = false;
		while(i<n){
			i = i + cell[i];
			if(i==t){	b = true;return b;  }
			else if(i>t){ return b; }
		}
		return b;
	}
	
	~A500(){
		if(!cell) delete[] cell;
	}
	
};

int main()
{
	A500 a;
	return 0;
}