#include <bits/stdc++.h>
using namespace std;


class Seive{
public:
	bool *A;
	vector<int> v;
	Seive(int n){
		A = new bool[n+1];
		for(int i=0; i<=n; i++){ A[i] = true;}
		A[0] = false; A[1] = false;
		
		int stop = (int)sqrt(n);
		for(int i=4; i<=n; i+=2){ A[i] = false; }
		
		for(int i=3; i<=stop; i++){
			if(A[i]==true){
				for(int j = 3*i; j<=n;j+=2*i){
					A[j]=false;
				}
			}
		}

		for(int i=0; i<=n; i++)
		{ 
			if(A[i]){v.push_back(i);}	
		}

	}
	~Seive(){
		if(!A){
			delete[] A;
		}
	}
};


int main()
{
    // call like this way
    
    Seive sv(2000000); 
    return 0;
}