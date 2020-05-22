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
	int n,m;
	string *s;
	
	map<int,int> mpx, mpy;
	cin>>n>>m;
	s = new string[n+1];
	

	int x[4], y[4];
	x[3] = 0; y[3] = 0;

	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	int k = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(s[i][j] == '*'){	x[k]=i; y[k]=j; k++; }
			if(k==3) break;
		}
	}

	for(int i=0; i<3; i++){		mpx[x[i]]++; mpy[y[i]]++;	}
	map<int,int>::iterator it;
	
	for(it = mpx.begin(); it!=mpx.end();  it++){
		if(it->second == 1){	x[3] = it->first; break; }
	}

	for(it = mpy.begin(); it!=mpy.end();  it++){
                if(it->second == 1){    y[3] = it->first; break; }
        }

	cout<<(x[3]+1)<<" "<<(y[3]+1)<<"\n";

	delete[] s;
    return 0;
}
