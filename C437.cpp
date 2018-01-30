#include <bits/stdc++.h>

using namespace std;

class C437
{
private:
	int n,m,result,x,y;
	int *v;
public:
	C437(){
		result = 0;
		cin>>n>>m;
		v = new int[n+1];
		for(int i=1; i<=n; i++){
			cin>>v[i];
		}

		for(int i=0; i<m; i++){
			cin>>x>>y;
			result+=min(v[x],v[y]);
		}
		cout<<result<<endl;
	}
	~C437(){  if(!v)delete[] v;	}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	C437 c437;
	return 0;
}