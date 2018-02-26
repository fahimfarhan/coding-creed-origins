#include <bits/stdc++.h>

using namespace std;

class Leaf{
public:
	bool isLeaf;
	bool validCafe;
	Leaf(){isLeaf = false; validCafe = true; }
};

class Node{
public:
	int n;
	bool isVisited;
	Node(){n=0; isVisited = false;}
};

class C580_C_Kefa_and_Park
{
private:
	int n,m,numOfCats;
	bool B;
	int *catPosition;
	Leaf *leaf;
	vector<int> *G;
	Node *node;
public:
	C580_C_Kefa_and_Park();
	void DFS();
	void DFS_visit(int u);
	~C580_C_Kefa_and_Park();
	
};

void C580_C_Kefa_and_Park::DFS_visit(int u){
	node[u].isVisited = true;
	int temp = numOfCats;
	if(catPosition[u]==1){ numOfCats++; }
	else{numOfCats = 0;} 
	bool tempB = B;
	if(numOfCats>m){ B = false; }



	if(leaf[u].isLeaf){leaf[u].validCafe = B; }

	for(int i = 0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!node[v].isVisited){
			DFS_visit(v);
		}
	}

	numOfCats=temp;
	B = tempB;
}

void C580_C_Kefa_and_Park::DFS(){
	for(int i=1; i<=n; i++){
		if(!node[i].isVisited){
			DFS_visit(i);
		}
	}
}

C580_C_Kefa_and_Park::	~C580_C_Kefa_and_Park(){
	if(!catPosition)delete[] catPosition;
	if(!leaf)delete[] leaf;
	if(!G)delete[] G;
	if(!node)delete[] node;
}

C580_C_Kefa_and_Park::	C580_C_Kefa_and_Park(){
	numOfCats = 0;
	B = true;
	int *x, *y;
	cin>>n>>m;
	node = new Node[n+1];
	x = new int[n+1];
	y = new int[n+1];
	catPosition = new int[n+1];
	G = new vector<int>[n+1];

	for(int i=1; i<=n; i++){
		cin>>catPosition[i];
	}
	
	for(int i=1; i<n; i++){
		cin>>x[i]>>y[i];
		 // if sth goes wrong, change it into 2 for loops	
	}

	for(int i=1; i<n; i++){
		G[x[i]].push_back(y[i]);
	}

	if(!x){ delete[] x;}
	if(!y){ delete[] y;}

	for(int i=1; i<=n; i++){
		if(G[i].size()==0) leaf[i].isLeaf = true;
	}

	DFS();
	int count = 0;
	for(int i=1; i<=n; i++){
		if(leaf[i].isLeaf && leaf[i].validCafe){
			count++;
		}
	}

	cout<<count;
}




int main(int argc, char const *argv[])
{
	/* code */
	C580_C_Kefa_and_Park a;
	return 0;
}