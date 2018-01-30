#include <bits/stdc++.h>
using namespace std;


class E909
{
private:
	vector<int> *G;
	vector<int> Stack;
	bool *isVisited;
	int *dependency, *E;
	int N,M, ans;
public:
	void DFS();
	void DFS_visit();
	E909(){
		ans = 0;
		cin>>N>>M;
		G = new vector<int>[N];
		isVisited = new bool[N];
		dependency = new int[N];
		E = new int[N];
		for(int i=0; i<N; i++){}

	}
	~E909(){
		if(!G)delete[] G;
		if(!isVisited)delete[] isVisited;
		if(!dependency)delete[] dependency;
	}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	E909 e909;
	return 0;
}