#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
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

    Seive sv(200000); 

    int n=1,m=1, r=1;
    cin>>n;

    for(int i=1; i<=1000; i++){
        r = n*i+1;
        if(!sv.A[r]){
            m = i;
            break;
        }
    }

    cout<<m<<"\n";


    return 0;
}
