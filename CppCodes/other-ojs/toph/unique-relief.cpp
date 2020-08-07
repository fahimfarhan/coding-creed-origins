/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;


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
		//cout<<"Stop = "<<stop<<endl;
		//int curr;
		// eliminate even numbers except 2
		for(int i=4; i<=n; i+=2){ A[i] = false; }
		// eliminate remaining numbers	
		for(int i=3; i<=stop; i++){
			if(A[i]==true){
				//curr = i;
				//v.push_back(i);
				//cout<<"pushed back = "<<i<<endl;
				//int temp = 2*curr;
				for(int j = 3*i; j<=n;j+=2*i){
					A[j]=false;
					//cout<<"j="<<j<<endl;
				}
			}
		}

		for(int i=0; i<=n; i++)
		{ 
			// cout<<i<<" "<<A[i]<<"\n";
			if(A[i]){v.push_back(i);}	
		}
		
		


	}
	~Seive(){
		if(!A){
			delete[] A;
		}
	}
};

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T, N, len;
    int lb=0;
    Seive seive(10009);
    ll *cf = new ll[seive.v.size()+1];
    len = seive.v.size();
    cf[0] = seive.v[0];
    for(int i=1; i<seive.v.size(); i++){
        cf[i] = seive.v[i]+cf[i-1];
    }

    for(int i=0; i<len; i++){    cout<<cf[i]<<" "; }cout<<"\n";

    cin>>T;
    while(T--){
        cin>>N;
        lb = lower_bound(cf, cf+len,N)-cf;
        cout<<(lb+1)<<"\n";
    
    }

    return 0;
}