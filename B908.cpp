#include <bits/stdc++.h>

using namespace std;

class B908
{
private:
	int n,m,x0,y0,ans;
	string way,*s;
	int dirX[4]={0,0,1,-1};
	int dirY[4]={1,-1,0,0};
	vector<int> dir;
public:
	B908(){
		cin>>n>>m;
		s = new string[n];
		for(int i=0; i<n; i++){
			cin>>s[i];
			for(int j=0; j<m; j++){
				if(s[i][j]=='S'){ x0=i;y0=j;}
			}
		}
		cin>>way;

		dir.push_back(0);dir.push_back(1);dir.push_back(2);dir.push_back(3);
		ans = 0;
		do{
			int x = x0;int y = y0;
			for(int i=0; i<way.size(); i++){
				int temp = way[i]-'0';
				x+=dirX[dir[temp]];
				y+=dirY[dir[temp]];

				if(x<0 || y<0 || x>=n || y>=m){ break; }
				if(s[x][y]=='#'){ break; }
				if(s[x][y]=='E'){ans++;break;}
			}

		}while(next_permutation(dir.begin(),dir.end()));

		cout<<ans<<endl;
	}
	~B908(){if(!s)delete[] s;}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	B908 b908;
	return 0;
}