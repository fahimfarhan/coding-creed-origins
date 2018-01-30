#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


class C893
{
private:
	ll sum, *c;
	vector<int> *G;
	bool *isVisited;
	int n,m, global;
public:
	void DFS(){
		for(int i=1; i<=n; i++){
			if(!isVisited[i]){
				global = INT_MAX;
				DFS_visit(i);
				sum+=global;
			}
		}
	}
	void DFS_visit(int u){
		isVisited[u] = true;
		if(c[u]<global) global = c[u];
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(!isVisited[v])
				DFS_visit(v);
		}
	}
	C893(){
		sum = 0;
		cin>>n>>m;
		c = new ll[n+1];
		G = new vector<int>[n+1];
		isVisited = new bool[n+1];

		for(int i=0; i<=n;i++){ isVisited[i] = false;	}
		for(int i=1; i<=n;i++){ cin>>c[i];	}
		for(int i=0; i<m; i++)
		{
			int x,y;
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}	

		DFS();
		cout<<sum<<endl;

	}
	~C893(){
		if(!c)delete[] c;
		if(!G)delete[] G;
		if(!isVisited)delete[] isVisited;
	}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	C893 c893;
	return 0;
}