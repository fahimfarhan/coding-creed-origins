#include <iostream>
#include <vector>
using namespace std;
const int MAXN=100000;
bool mark[MAXN];
bool cat[MAXN];
int m;
int n;
int ok=0;
vector <int> v[MAXN];
void DFS(int i,int c)
{
	mark[i]=true;
	int l=0;
	if(cat[i]==1)
		c++;
	else c=0;
	if(c>m)
		return;
	for(int j:v[i])
		if(!mark[j])
		{
			DFS(j,c);
			l++;
		}
	if(l==0)
		ok++;
}
int main()
{
	cin>>n>>m;
	int x,y;
	for(int i=0;i<n;i++)
		cin>>cat[i];
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(0,0);

	cout<<ok;
}