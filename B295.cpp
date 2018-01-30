#include <bits/stdc++.h>

using namespace std;

class B295{
private:
	int N;
	long long *q, **D, **P, *x, n;
public:
	B295()
	{
		cin>>N;
		q = new long long[N];
		D = new long long*[N];
		for(int i=0; i<N; i++){
			D[i] = new long long[N];
		}

		P = new long long*[N];
		for(int i=0; i<N; i++){
			P[i] = new long long[N];
		}

		x = new long long[N];


		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){ cin>>P[i][j]; }
		}

		for(int i=0; i<N; i++){ cin>>x[i]; }

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){ D[i][j] = P[x[N-i+1]][x[n-j+1]]; }
		}

		for(int k=0; k<N; k++){
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++)
					{ D[i][j] = min(D[i][j], D[i][k]+D[k][j]); }
			}
		
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++)
					{ q[N-k+1]+=D[i][j]; }
			}
		}		
		
		for(int i=0; i<N; i++){
			cout<<q[i]<<" ";
		}


	}
	~B295()
	{
		if(!q) delete[] q;
		//if(!P) delete[] P;
		if(!x) delete[] x;
		for(int i=0; i<N; i++){
			if(!D[i]) delete[] D[i];
		}
		if(!D) delete[] D;

		for(int i=0; i<N; i++){
			if(!P[i]) delete[] P[i];
		}
		if(!P) delete[] P;
	}
};

int main()
{
	B295 ob;
	return 0;
}