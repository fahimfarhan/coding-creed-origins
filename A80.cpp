#include <bits/stdc++.h>

#define np 1
#define isp 0

using namespace std;

class A80
{
private:
	int n,m,*A;
	vector<int> v;
public:
	A80(){
		cin>>n>>m;
		A = new int[m+1];
		A[0]=np;
		A[1]=np;
		for(int i=4; i<=m; i+=2){if(i%2==0)A[i]=np;}
		for(int i=3; i<sqrt(m)+1; i+=2){
			if(A[i]==isp){
				//v.push_back(i);
				for(int j=3*i; j<=m; j+=2*i){
					A[j]=np;
				}

			}
		}
		//for(int i=0; i<=m; i++){
		//	cout<<i<<"->"<<A[i]<<" ";
		//}cout<<endl;

		bool b = true;
		if(A[m]==np){b=false;}
		for(int i=n+1; i<m;i++){
			if(A[i]==isp){b=false; break;}
		}

		if(b)cout<<"YES\n";
		else cout<<"NO\n";

	}
	~A80(){if(!A)delete[] A;}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	A80 a80;
	return 0;
}