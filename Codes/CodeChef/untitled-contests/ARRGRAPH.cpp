#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int T, N;
int *g;
set<int> *s;

void coprimelist(){
    s = new set<int>[55];
    for(int i=2; i<=50; i++){
        for(int j=i; j<=50; j++){
            if(j%i!=0){
                s[i].insert(j);
                s[j].insert(i);
            }
        }
    }
}

void destructor(){
    if(!s)delete[] s;
}

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
    
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int n;
    coprimelist();

    cin>>T;
    while(T--){
        cin>>N;
        g = new int[N+1];
        int minimus = INT_MAX;
        int maximus = INT_MIN;
        for( int i=0; i<N; i++ ){
            cin>>g[i];
            if(g[i]>maximus){   maximus=g[i]; }
            if(g[i]<minimus){   minimus=g[i]; }
        }

        if(!g)delete[] g;
    }

    destructor();
	return 0;
}
