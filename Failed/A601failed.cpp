#include <bits/stdc++.h>

using namespace std;

class A601
{
private:
	int n,m;
	bool **G;
	queue<int> q;
	int *d;
public:
	A601();
	int BFS(bool vehicle);
	~A601();
	
};

int A601::BFS(bool vehicle){
	d[0] = 1;
	q.push(0);

	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i=0; i<n; i++){
			if(G[u][i]==vehicle && !d[i]){
				d[i] = d[u] + 1;
				if(i==n-1) return d[i];
				q.push(i);
			}
		}
	}

	return 0;
}
A601::A601(){
	scanf("%d %d",&n,&m);
	G = new bool*[n+1];
	d = new int[n+1];
	for(int i=0; i<=n; i++){
		G[i] = new bool[n+1];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			G[i][j] = false;
	}
	for(int i=0; i<m; i++){
		int u,v;
		scanf("%d %d",&u,&v);
		u--; v--;
		G[u][v] = G[v][u] = true;
	}
	cout<<"G[0][n-1] = "<<G[0][n-1]<<endl;
	int ans = BFS(!G[0][n-1])-1;
	printf("%d",ans);
	//return 0;

}
A601::~A601(){
	for(int i=0; i<=n; i++){
		if(!G[i])delete[] G[i];
	}	
	if(!G)delete[] G;
	if(!d)delete[] d;
}

int main(){
	A601 a601;
	return 0;
}