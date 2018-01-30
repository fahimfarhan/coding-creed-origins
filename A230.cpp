#include <bits/stdc++.h>
using namespace std;

class dragon{
public:
	int x,y;
	dragon(){x = 0; y = 0; }
};


// Sort Container by age function
bool sortByX(const dragon &lhs, const dragon &rhs) { return lhs.x < rhs.x; }

class A230
{
private:
	vector<dragon> v;
	int s,n, *x, *y;
public:
	A230()
	{
		cin>>s>>n;
		x = new int[n];
		y = new int[n];
		for(int i=0; i<n; i++){
			cin>>x[i]>>y[i];
		}

		for(int i=0; i<n; i++){
			dragon d;
			d.x = x[i]; d.y = y[i];
			v.push_back(d);
		}

		sort(v.begin(), v.end(), sortByX);
		bool b = true;
		for(int i=0; i<n; i++){
			if(s>v[i].x){ s = s+v[i].y;}
			else{b = false; break;}
		}

		if(b) cout<<"YES\n";
		else  cout<<"NO\n";

	}
	~A230(){}
	
};

int main()
{
	A230 a;
	return 0;
}



