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
    int N, maximus = -1;
    bool **a;
    int *sum;
    cin>>N;
    sum = new int[N];
    for(int i=0; i<N; i++){ sum[i] = 0; }
    a = new bool*[N];
    for(int i=0; i<N; i++){
        a[i] = new bool[N];
    }

    char c;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>c;
            if(c=='T'){
                a[i][j] = 1;
            }else{ a[i][j] = 0; }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sum[i]+=a[j][i];
        }
        maximus = max(maximus, sum[i]);
    }

    int count = 0;
    for(int i=0; i<N; i++){
        if(maximus == sum[i]){  count++; }
    }
    cout<<count<<"\n";

for(int i=0; i<N; i++){
        delete[] a[i]; // = new int[N];
    }
    delete[] a;
  
  return 0;
}
