#include <bits/stdc++.h>

using namespace std;


class A469{
private:
	int n,p,q,x,count, *P, *Q, *A;
	bool b; 
public:
	A469()
	{
		count = 0;
		cin>>n;

		A = new int[n+1];
		for(int i=0; i<=n; i++){ A[i] = 0; }
		cin>>p; //P = new int[p];
		for(int i=0; i<p; i++){ cin>>x; if(A[x]==0){ A[x] = x; count++;} }

		cin>>q; //Q = new int[q];
		for(int i=0; i<q; i++){ cin>>x; if(A[x]==0){ A[x] = x; count++;} }

		//A = new int[p+q];
		//for(int i=0; i<p; i++){ A[i] = P[i]; }
		//for(int i=p; i<p+q; i++){ A[i] = Q[i]; }
		//int len=p+q;
		//sort(A, A+n+1);

			if(n==count)cout<<"I become the guy.\n";
		else cout<<"Oh, my keyboard!\n";
/*		b=false;
		if(A[len-1]==n){b=true;}
		if(b){
			for(int i=1; i<len; i++){
				if((A[i]-A[i-1])>1){ b=false; break; }
			}
		}

		if(b) cout<<"I become the guy.\n";
		else cout<<"Oh, my keyboard!\n";	
*/
	}
	~A469()
	{
		if(!P) delete[] P;
		if(!Q) delete[] Q;
		if(!A) delete[] A;
	}
};
int main()
{
	A469 ob;
	return 0;
}