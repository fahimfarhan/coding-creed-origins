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
		//v.push_back(2);
		int stop = (int)sqrt(n);
		cout<<"Stop = "<<stop<<endl;
		//int curr;
		// eliminate even numbers except 2
		for(int i=4; i<=n; i+=2){ A[i] = false; }
		// eliminate remaining numbers	
		for(int i=3; i<=stop; i++){
			if(A[i]==true){
				//curr = i;
				//v.push_back(i);
				cout<<"pushed back = "<<i<<endl;
				//int temp = 2*curr;
				for(int j = 3*i; j<=n;j+=2*i){
					A[j]=false;
					cout<<"j="<<j<<endl;
				}
			}
		}

		for(int i=0; i<=n; i++)
		{ 
			cout<<i<<" "<<A[i]<<"\n";
			if(A[i]){v.push_back(i);}	
		}
		
		vector<int>::iterator it;
		for(it = v.begin(); it!=v.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;

	}
	~Seive(){
		if(!A){
			delete[] A;
		}
	}
};

int main()
{
	int n=0;
	cout<<"Enter n: ";
	cin>>n;
	Seive *s = new Seive(n);
	return 0;
}

/*class Seive{
public:
	//vector<int> Prime, mark;
	int *Prime, *mark;	
	int nPrime, n;

	Seive(int m){
		n = m;
		int limit = sqrt(n)+2;
		mark = new int[n+1];
		Prime = new int[n+1];

		for(int i=0; i<=n; i++){
			mark[i] = 0;
			Prime[i] = -1;
		}

		mark[0] = 1; mark[1]=1; // since 0, 1 aren't prime

		for(int i=4; i<=n; i+=2 ){
			mark[i] = 1;
		}


	}
	~Seive(){}

};
*/
