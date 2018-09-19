#include <bits/stdc++.h>


using namespace std;


int main()
{
	int N, Q, C;
	C=0;
	while(cin>>N>>Q){
		if( (N==0) && (Q==0) ){	break;	}
		C++;
		cout<<"CASE# "<<C<<":\n";	
		int *a;
		a = new int[N];
		
		for(int i=0; i<N; i++){	cin>>a[i];	}
		sort(a,a+N);
		while(Q--){
			int n;
			cin>>n;
			int lb = lower_bound(a,a+N,n)-a;
			if(a[lb]==n){
				cout<<n<<" found at "<<lb+1<<"\n";
			}
			else{
				cout<<n<<" not found\n";
			}	
		}
		if(!a)delete[] a;
	}

	return 0;
}
