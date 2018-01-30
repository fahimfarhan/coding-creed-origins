#include <bits/stdc++.h>

using namespace std;

class B908
{
private:
	int n,m,x0,y0,xn,yn,ans;
	char **G;
	bool **isVisited;
	vector<char> Stack;
	string s;
public:

	void DFS(){
		DFS_visit(x0,y0);
		cout<<"d2\n";
	}

	void DFS_visit(int a,int b){
		cout<<"a="<<a<<",b="<<b<<endl;
		cout<<"d3\n";
		isVisited[a][b] = true;
		if(G[a][b]=='E'){
			if(Stack.size() == s.length()){
				ans++;
			}return;
		}
		cout<<"d4\n";
		if(((a-1)>=0) && (!isVisited[a-1][b]) && (G[a-1][b]!='#')){ Stack.push_back('L'); DFS_visit(a-1,b); Stack.pop_back();}
		cout<<"d5\n";
		if(((a+1)<m) && (!isVisited[a+1][b]) && (G[a+1][b]!='#') ){ Stack.push_back('R'); DFS_visit(a+1,b); Stack.pop_back();}
		cout<<"d6\n";
		if(((b-1)>=0) && (!isVisited[a][b-1]) && (G[a][b-1]!='#')){ Stack.push_back('D');DFS_visit(a,b-1); Stack.pop_back();}
		cout<<"d7\n";
		if(((b+1)<n) && (!isVisited[a][b+1]) && (G[a][b+1]!='#') ){ Stack.push_back('U'); DFS_visit(a,b+1); Stack.pop_back();}
	}

	B908(){
		ans = 0;
		cin>>n>>m;
		G = new char*[n+10];
		isVisited = new bool*[n+10];
		for(int i=0; i<n; i++){ G[i]=new char[m+10]; isVisited[i] = new bool[m+10];}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>G[i][j];
				if(G[i][j]=='S'){x0=i;y0=j;}
				if(G[i][j]=='E'){xn=i;yn=j;}
			}
		}

		cin>>s;

		/*for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout<<G[i][j];
			}cout<<endl;5 6
.....#
S....#
.#....
.#....
...E..
333300012
		}	
		cout<<s<<endl;
		cout<<G[x0][y0]<<G[xn][yn]<<endl;*/
		cout<<"d1\n";
		DFS();
		cout<<ans<<endl;

	}
	~B908(){
		for(int i=0; i<n; i++){
			if(!G[i])delete[] G[i];
			if(!isVisited[i])delete[] isVisited;
		}
		if(!G)delete[] G;
		if(!isVisited)delete[] isVisited;
	}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	B908 b908;
	return 0;
}