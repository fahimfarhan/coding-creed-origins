#include <bits/stdc++.h> 

using namespace std;

class Node{
public:
	int u, w;
	Node(){u=0; w=0;}
};

class Graph{
private:
	int V, E, n, left, right, count;
	vector<Node> *g;
	Node *node;
int v1;

public:

	int Left(int i){
		if(i>v1){ return node[2*i].w;}
		else return  node[2*i].w+Left(4*i)+Right(4*i+1);
	}

	int right(int i){
		if(i>v1){ return node[2*i+1].w;}
		else return node[2*i+1].w + Left(4*i+2)+Right(4*i+3);
	}

	Graph(){
		cin>>n;
		V = (int)pow(2,n+1)-1;
		E = (int)pow(2,n+1)-2;
		node = new Node[V+1];// 1 based indexing... ...

		g = new vector<Node>[V+1];// cz 1 based indexing... ... ...

		v1 = (int)pow(2,n)-1;
		
		for(int i=1; i<=V; i++){
			int w;	// take input edges
			cin>>w; node[i].u = i; node[i].w = w;
		}

		for(int i=1; i<=v1; i++){
			g[i].push_back(node[2*i]);
			g[i].push_back(node[2*i+1]);
		}

		/*The main algo*/
		left=0; right = 0;
		count = 0; 
		for(int i=v1; i>0;i--){
			int l=0; int r = 0;
			l = left+g[i][0].w;
			r = right+g[i][1].w;
			int temp=0;
			
			if(l>r){temp = l-r;} 
			else{temp = r-l;}
			count+=temp;
			if(i%2==0){left = left+l+r+temp; }
			else{ right = right+l+r+temp; } 
		}

		cout<<count<<"\n";

	}

	~Graph(){
		if(!g)delete[] g;
		if(!node)delete[] node;
	}
};


int main()
{
	Graph G;
	return 0;
}