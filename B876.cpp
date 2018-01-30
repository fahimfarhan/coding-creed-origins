#include <bits/stdc++.h>

using namespace std;

class B876{

private:
	int n,k,m;
	vector<int> *v;
public:
	B876(){
		cin>>n>>k>>m;
		v = new vector<int>[n];
		int count=n;
		while(count--){
			int x;
			cin>>x;
			v[x%m].push_back(x);
		}

		bool b = false;

		for(int i=0; i<n; i++){
			if(v[i].size()>=k){
				b = true;
				cout<<"YES\n";
				for(int j=0; j<k; j++)
					{ cout<<v[i][j]<<" ";}
				 break;
				}
			}

			if(!b) cout<<"NO\n";
		}
		
		~B876(){ 
		if(!v) delete[] v;
	}

	};

	


int main()
{

	B876 obj;
	return 0;
}