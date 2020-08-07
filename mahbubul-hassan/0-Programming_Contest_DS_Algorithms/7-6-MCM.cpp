#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int *a;
	int n;
int matrixChainMultiplication(){
    int m[n][n];

    for(int i=0; i<n; i++){
        m[i][i] = 0;
    }

    for(int L=2; L<n; L++){
        for(int i=1; i<n-L+1; i++){
            int j=i+L-1;
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-i; k++){
                int q = m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n-1];
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


    cout<<"Enter # of matrices: \n";
    cin>>n;
    a = new int[n+1];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<"Ans = "<<matrixChainMultiplication();

    delete[] a;
	return 0;
}
