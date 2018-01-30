#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

class MyPair{
public:
	int i,j;
	MyPair(){i=0;j=0;}
};

class C437
{
private:
	vector<int> *G;
	int *v;
	MyPair *totalEnergy;
	int x,y,n,m,ans;
public:
	C437();
	~C437();
	void removeVi(int Vi);
	void calculateEnergyLevel();
	

};

void C437::calculateEnergyLevel(){
	for(int i=1; i<=n; i++){
		totalEnergy[i].i = i;
		totalEnergy[i].j = 0;
		for(int j=0; j<G[i].size(); j++){
			totalEnergy[i].j = totalEnergy[i].j+v[G[i][j]];
		}
		cout<<"totalEnergy["<<i<<"] "<<totalEnergy[i].j<<endl;
	}
}

void C437::removeVi(int vi){
	vector<int>::iterator it;
	for(int i=1; i<=n; i++){
		for(it = G[i].begin(); it!=G[i].end();it++){
			if(*it == vi){
				G[i].erase(it);
			}
		}
	}
}

bool compare(const MyPair&n, const MyPair&m)
{
    return n.j < m.j;
}
	

C437::C437()
{
	ans = 0;
	scanf("%d %d", &n,&m);
	
	G = new vector<int>[n+1];
	v = new int[n+1];
	totalEnergy = new MyPair[n+1];
	for(int i=1; i<=n; i++){
		totalEnergy[i].i=i;
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&v[i]);
	}

	for(int i=1; i<=m; i++){
		scanf("%d %d", &x,&y);
		G[x].push_back(y);
		G[y].push_back(x);		
	}
	for(int i=1;i<=n;i++){
		calculateEnergyLevel();
		sort(totalEnergy,totalEnergy+n+1,compare);
		int j=0;
		for(int j=1; j<=n; j++){
			if(totalEnergy[j].j != 0) break;
		}
		cout<<j<<endl;
		ans = ans+totalEnergy[j].j;
		removeVi(totalEnergy[j].i);
	}	
	printf("%d", ans);
}
C437::~C437()
{	
	if(!G){	delete[] G;}
	if(!v) {delete[] v;}
	if(!totalEnergy) {delete[] totalEnergy;}
}

int main(int argc, char const *argv[])
{
	/* code */
	C437 c437;
	return 0;
}