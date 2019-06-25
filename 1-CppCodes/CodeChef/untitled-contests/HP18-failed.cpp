#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
bool *isvisited;




int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T,N,a,b;
  ll  *A, aliceCount, bobCount;
  cin>>T;
  while(T--){
      cin>>N>>a>>b; // bob--> a , alice --> b 
      if( (a > b) && ((a%b) == 0) ){  cout<<"ALICE\n";  }
      else if( (b > a) && ((b%a) == 0) ){cout<<"BOB\n";}
      else{
                A = new ll[N];
                aliceCount = 0; bobCount = 0;

                for(int i=0; i<N; i++){
                    cin>>A[i];
                    if(A[i]%a == 0){  bobCount++;     }
                    if(A[i]%b == 0){  aliceCount++;   }
                }
                if(bobCount>=aliceCount){ cout<<"BOB\n";  }
                else{ cout<<"ALICE\n";    }
                delete[] A;
      }

  }

  
  return 0;
}
