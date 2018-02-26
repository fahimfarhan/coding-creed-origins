#include <bits/stdc++.h>
//int min = INT_MIN; // minimum value
int max = INT_MAX;

//int imin = std::numeric_limits<int>::min(); // minimum value
//int imax = std::numeric_limits<int>::max();
using namespace std;

class B574
{
private:
	int n,m, count,combination;//, m1,m2,m3;
	vector<int> v;
	vector<int> *G;
	bool *isVisited;
	int *rank;
public:
	void DFS();
	void SolN();
	void DFS_Visit(const int &i);
	bool isTrue1(int length){
		return length >=3 && (v[length-1]>=0) && (v[length-2]>=0) && (v[length-3]>=0); 
	}
	bool isTrue(int i, int j, int k){
		return (rank[i]>=0)&&(rank[j]>=0)&&(rank[k]>=0);
	}
	bool dudesKnowEachOther(int i,int k);
	B574();
	~B574();
	
};


bool B574::dudesKnowEachOther(int i,int k){
	bool b1, b2;
	b1 = false;
	b2 = false;
	for(int j=0; j<G[i].size(); j++){
		if(G[i][j]==k){
			b1 = true; break;
		}
	}

	for(int j=0; j<G[k].size(); j++){
		if(G[k][j]==i){
			b2 = true; break;
		}
	}
	return b1 && b2;
}

void B574::SolN(){
	int p,q,r;
	for(int i=1; i<=n; i++){
		for(int j=0; j<G[i].size(); j++){
			p = G[i][j];
			for(int k=0; k<G[j].size(); k++){
				q = G[j][k];
				if((i!=q) && dudesKnowEachOther(i,q) && isTrue(i,p,q)){
					count = min(count,rank[i]+rank[p]+rank[q]);
					//cout<<rank[i]<<" "<<rank[p]<<" "<<rank[q]<<" "<<count<<endl;
				}
			}
		}
	}


}
void B574::DFS_Visit(const int &u){
	isVisited[u] = true;
	v.push_back(rank[u]);

	/*The main part!*/
	int length = v.size();
	if(isTrue1(length)){
		
		count = min(count,v[length-1] + v[length-2] + v[length-3]);
		
	}
	/*end*/

	for(int i=0; i<G[u].size(); i++){
		int w = G[u][i];
		if(isVisited[w]==false){
			DFS_Visit(w);
		}
	}

	v.pop_back();
}
void B574::DFS(){
	for(int i=1; i<=n; i++){
		if(isVisited[i]==false){
			DFS_Visit(i);
		}
	}
}

B574::~B574()
{
	if(!G)delete[] G;
}

B574::B574(){
	count = INT_MAX;
	combination = 0;

	cin>>n>>m;
	G = new vector<int>[m+10];
	isVisited = new bool[n+10];
	rank = new int[n+1];
	for(int i=0; i<=n; i++){
		rank[i] = -2;
	}
	int x,y; 
	for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
		rank[x]++;
		rank[y]++;
	}

	for(int i=0; i<=n; i++){
		isVisited[i] = false;
		//cout<<"rank#"<<i<<" "<<rank[i]<<"\n";
	}

	//DFS();
	SolN();
	//cout<<count<<endl;
	if(count<INT_MAX) cout<<count<<endl;
	else cout<<"-1\n";
}
int main(int argc, char const *argv[])
{
	/* code */
	B574 b574;
	return 0;
}

/*
5 6
1 2
1 3
2 3
2 4
3 4
4 5

 */
/*
12 66
9 12
1 4
8 4
5 3
10 5
12 2
3 2
2 7
1 7
3 7
6 2
4 2
6 10
8 10
4 6
8 5
12 6
11 9
7 12
5 4
11 7
9 4
10 4
6 3
1 6
9 7
3 8
6 11
10 9
3 11
11 1
5 12
8 2
2 1
3 1
12 4
3 9
10 12
8 11
7 10
11 5
9 5
8 7
11 4
8 1
2 11
5 1
3 4
8 12
9 2
10 11
9 1
5 7
10 3
11 12
7 4
2 10
12 3
6 8
7 6
2 5
1 10
12 1
9 6
8 9
6 5

 */