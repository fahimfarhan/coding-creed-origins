#include <bits/stdc++.h>

using namespace std;

class C580
{
private:
	int n,m,*a,cat, count;
	vector<int> *G;
	bool *nodeIsVisited;
public:
	C580();
	void DFS();
	void DFS_visit(int i,int c);
	~C580();
	
};

void C580::DFS_visit(int u,int c){
	nodeIsVisited[u] = true;
	//int temp = cat;
	int isNotLeaf = 0;
	if(a[u]==1){ c++; }
	else{ c = 0; }
	if(c>m){
		return;
	}

	for(int i=0; i<G[u].size(); i++){
		if(!nodeIsVisited[i]){
			isNotLeaf++;
			DFS_visit(i,c);
		}
	}
	if(isNotLeaf==0){
		count++;
	}
	//cat = temp;
}

void C580::DFS(){
	for(int i=1; i<=n; i++){
		if(!nodeIsVisited[i])
		{	DFS_visit(i,0);	}
	}
}

C580::~C580(){
	if(!a)delete[] a;
	if(!G)delete[] G;
}

C580::C580(){
	cin>>n>>m;
	count = 0; cat = 0;
	a = new int[n+1];
	nodeIsVisited = new bool[n+1];
	G = new vector<int>[n+1];
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}

	int x,y;
	for(int i=1; i<n; i++){
		cin>>x>>y;
		G[x].push_back(y);
	}

	for(int i=0; i<=n; i++){ nodeIsVisited[i] = false;}

	DFS();
	cout<<count<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	C580 c580;
	return 0;
}