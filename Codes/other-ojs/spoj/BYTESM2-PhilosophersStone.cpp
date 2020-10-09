#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

#define LOL 5

int n, T, h,w,m;
int **a, **dp;
    
int f(int i,int j){
    if(i==(h+LOL) ){   return 0; }
    if(dp[i][j]!=-1){   return dp[i][j];}
    int maximus = 0;
    if(j-1>0){  maximus = max(maximus,f(i+1,j-1) ); }
    maximus = max(maximus, f(i+1,j)  );
    if(j+1 < w){    maximus = max(maximus, f(i+1,j+1) ); }

    return dp[i][j] = maximus+a[i][j];
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

	cin>>T;
    while(T--){
        cin>>h>>w;
        a = new int*[h+2*LOL];
        dp = new int*[h+2*LOL];
        for(int i=0; i<w+2*LOL;i++){ a[i] = new int[w+2*LOL]; dp[i] = new int[i+2*LOL]; }

        for(int i=0+LOL; i<h+LOL; i++){
            for(int j=0+LOL; j<w+LOL; j++){
                cin>>a[i][j];
                //dp[i][j]=-1;
            }
        }

        for(int i=0; i<h+2*LOL; i++){
            for(int j=0; j<w+2*LOL; j++){
                dp[i][j] = -1;
            }
        }
        int maximus=0;
        for(int i=0+LOL; i<w+LOL; i++){
            maximus=max(maximus, f(0+LOL,i));
        }
        cout<<maximus<<"\n";

        for(int i=0; i<w;i++){ delete[] a[i]; delete[] dp[i]; }
        delete[] dp;
        delete[] a;
    }
	return 0;
}
