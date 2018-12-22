#include <bits/stdc++.h>

class F908
{
private:
	int n, *A;
	int prev_green,next_green,prev_red, next_red, prev_blue, next_blue;
	char *C;
	int count;

public:
	F908(){
		count = 0;
		cin>>n;
		A = new int[n];
		C = new int[n];

		for(int i=0; i<n; i++){
			cin>>A[i]>>C[i];
		}
	}
	~F908(){
		if(!A)delete[] A;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	F908 f908;
	return 0;
}