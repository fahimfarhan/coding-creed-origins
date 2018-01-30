#include <bits/stdc++.h>
//typedef long long int ll;
#define INF numeric_limits<int>::max()
using namespace std;

class B514{
private:
	int N, x0, y0, xi, yi;
	double *slope;
	int count;
public:
	B514()
	{
		cin>>N>>x0>>y0;
		slope = new double[N];
		for(int i=0; i<N; i++)
		{ 
			cin>>xi>>yi;
			if((xi-x0)!=0)slope[i] = (yi-y0)/(xi-x0);
			else slope[i] = INF;
		}

		sort(slope, slope+N);
		if(N==0){count=0;}else{count=01;}
		for(int i=1; i<N; i++){
			if(slope[i-1]<slope[i]){count++;}
		}

		cout<<count;

	}
	~B514(){if(!slope) slope = NULL; }
};

int main()
{
	B514 b;
	return 0;
}