

#include <bits/stdc++.h>

using namespace std;

class A217
{
private:
	int n, ans;
	int *x, *y;bool *v;

public:
	A217(){
        ans=0;
		cin>>n;
		x = new int[n+1];
		y = new int[n+1];
		v = new bool[n+1];

		for(int i=0;i<n;i++) {cin>>x[i]>>y[i]; v[i]=false; }
		for(int i=0;i<n;i++)if(!v[i]){
			dfs(i);
			ans++;
		}
		cout<<(ans-1)<<endl;
	}

	void dfs(int i){
	v[i]=true;
	for(int j=0;j<n;j++)
		if( (!v[j]) && ( (x[i]==x[j]) || (y[i]==y[j]) ))
			dfs(j);
}
	~A217(){
		if(!x){delete[] x;}
		if(!y){delete[] y;}
		if(!v){delete[] v;}
	}
	
};

int main()
{
	A217 a;
	return 0;
}