#include <bits/stdc++.h>
using namespace std;

class G911
{
private:
	//int n,q,*l,*r,*x,*y, *a;
	int n,q,l,r,x,y, *a;
public:
	G911(){
		cin>>n;
		a = new int[n+1];
		for(int i=01; i<=n; i++){
			cin>>a[i];
		}
		cin>>q;
		
		for(int i=0; i<q; i++){
			
			cin>>l>>r>>x>>y;
			for(int j=l; j<=r; j++){
				if(x==a[j]){a[j] = y; }
			}

		}

		
		for(int i=01; i<=n; i++){
			cout<<a[i]<<" ";
		}cout<<endl;
	}
	~G911(){
		if(!a)delete[] a;
	}
	
};

int main(int argc, char const *argv[])
{
	
	G911 g911;
	return 0;
}