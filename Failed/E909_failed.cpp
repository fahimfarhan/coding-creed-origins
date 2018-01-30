#include <bits/stdc++.h>

using namespace std;


class E909
{
private:
	int N,M, *E,prev_value;
	vector<int> *G;
	bool *isVisited;
	vector<int> Stack;
	long long int result;

public:
	void Calculation(){
		int temp,pos;
		pos = 0;
		temp = E[Stack[pos]];
		if(temp)result++;
		pos++;
		while(pos<N){

		}
		/*while(pos<N){
			int index = Stack[pos];
			temp = E[index];
			if(temp == 1){
				result++;
				while(E[Stack[pos]]!=0){ pos++; }	
			}else{
				while(E[Stack[pos]]!=1){ pos++; }
			}	
		}*/
		
	}

	void DFS(){
		prev_value= 0;
		for(int i=0; i<N; i++){
			if(!isVisited[i]){
				DFS_visit(i);
			}
		}
	}
	void DFS_visit(int u){
		isVisited[u] = true;
		if(prev_value==0 && E[u]==1){ result++;}
		prev_value = E[u];
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(!isVisited[v]){
				DFS_visit(v);
			}
		}
		Stack.push_back(u);
	}

	E909(){
		result = 0;
		cin>>N>>M;
		E = new int[N];
		G = new vector<int>[N];
		isVisited = new bool[N];
		for(int i=0; i<N; i++){
			isVisited[i] = false;
		}

		for(int i=0; i<N; i++){
			cin>>E[i];
		}
		for(int i=0; i<M;i++){
			int x,y;
			cin>>x>>y;
			//G[y].push_back(x);
			G[x].push_back(y);
		}
		DFS();
		//Calculation();
		for(int i=0; i<N; i++){
			cout<<Stack[i]<<"-";
		}
		cout<<endl;
		cout<<result<<endl;
	}
	~E909(){
		if(!E)delete[] E;
		if(!G)delete[] G;
		if(!isVisited)delete[] isVisited;
	}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	E909 e909;
	return 0;
}