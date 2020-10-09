#include<bits/stdc++.h>

using namespace std;

class B492{
private:
	int n, l, *a;
public:
	B492(){
		cin>>n>>l;
		a = new int[n];
		for(int i=0; i<n; i++){	cin>>a[i];	}
		sort(a,a+n);
		int m = max(a[0], l-a[n-1])*2;

		for(int i=1; i<n; i++){
			m = max(m, a[i]-a[i-1]);
		}
		
		printf("%lf",m/2.0);
	}

	~B492(){ if(!a) delete[] a; }

};

int main(){
	B492 a;
}






