#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
class A911
{
private:
	int n; 
	ll count, *a;
public:
	A911(){
		scanf("%d",&n);
		a = new ll[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		sort(a,a+n);
		count = 0;
		for(int i=1; i<n; i++){
			 count++;
			if(a[i]!=a[0])break;
			
		}
		//if(n==2){ count--;}
		cout<<count<<endl;
	}
	~A911(){if(!a)delete[] a;}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	A911 a911;
	return 0;
}