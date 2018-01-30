#include <bits/stdc++.h>
using namespace std;

class A576
{
private:
	int n;
	bool *A;
	vector<int> v;
	vector<int> sol;
public:
	int Seive(int sn);
	A576();
	~A576();
	
};
A576::~A576(){if(!A)delete[] A;}
A576::A576(){
	cin>>n;//scanf("%d",&n);
	A = new bool[n+1];
	cout<<"ok1"<<endl;
	Seive(n);
	cout<<"ok2"<<endl;
	for(int i=0; i<v.size(); i++){
		int x = v[i];
		while(x<=n){
			sol.push_back(x);
			x = x*i;
		}
	}
	cout<<"ok3"<<endl;

	int len = sol.size();
	printf("%d",len);
	for(int i=0; i<len; i++){
		cout<<sol[i];
	}
	cout<<"ok4"<<endl;
}

int A576::Seive(int n){
		
		for(int i=0; i<=n; i++){ A[i] = true;}
		A[0] = false; A[1] = false;
		//v.push_back(2);
		int stop = (int)sqrt(n);
		//cout<<"Stop = "<<stop<<endl;
		//int curr;
		// eliminate even numbers except 2
		for(int i=4; i<=n; i+=2){ A[i] = false; }
		// eliminate remaining numbers	
		for(int i=3; i<=stop; i++){
			if(A[i]==true){
				for(int j = 3*i; j<=n;j+=2*i){
					A[j]=false;
					//cout<<"j="<<j<<endl;
				}
			}
		}

		for(int i=0; i<=n; i++)
		{ 
			//cout<<i<<" "<<A[i]<<"\n";
			if(A[i]){v.push_back(i);}	
		}
		/*
		vector<int>::iterator it;
		for(it = v.begin(); it!=v.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;*/

	}

int main(int argc, char const *argv[])
{
	/* code */
	A576 a576;
	return 0;
}