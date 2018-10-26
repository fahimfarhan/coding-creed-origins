#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

/*
int x1,x2,a1,b1,c1,m1;
int y1,y2,a2,b2,c2,m2;
int z1,z2,a3,b3,c3,m3;
*/
int a1,a2,a3,b1,b2,b3,c1,c2,c3,m1,m2,m3;
int *x,*y,*z,*l,*r, *k;

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int T,N,Q;
    cin>>T;
    int caseno=1;
    while(T--){
        vector<int> v;
        cin>>N>>Q;
        x = new int[N+1];
        y = new int[N+1];
        z = new int[Q+1];

        l = new int[N+1];
        r = new int[N+1];
        k = new int[Q+1];

        cin>>x[1]>>x[2]>>a1>>b1>>c1>>m1;
        cin>>y[1]>>y[2]>>a2>>b2>>c2>>m2;
        cin>>z[1]>>z[2]>>a3>>b3>>c3>>m3;

        for(int i=3;  i<=N; i++){
            x[i] = (a1)*(x[i-1]%m1) + (b1)*(x[i-2]%m1) + c1 ; 
            // Xi = (A1 × Xi - 1 + B1 × Xi - 2 + C1) modulo M1, for i = 3 to N.
            y[i] = a2*(y[i-1]%m2)+b2*(y[i-2]%m2)+c2;
            // Yi = (A2 × Yi - 1 + B2 × Yi - 2 + C2) modulo M2, for i = 3 to N
        }

        for(int i=1; i<=N; i++){
            l[i] = min(x[i], y[i])+1;
            r[i] = max(x[i], y[i])+1;

            for(int j=l[i]; j<=r[i]; j++){
                v.push_back(j);
            }
        }

        int lengggggttthhh = v.size();
        sort(v.begin(), v.end());

        for(int i=3; i<=Q; i++){
            z[i] = a3*(z[i-1]%m3)+b3*(z[i-2]%m3)+c3;
        }
        // Zi = (A3 × Zi - 1 + B3 × Zi - 2 + C3) modulo M3, for i = 3 to Q.


        for(int i=1; i<=Q; i++){
            k[i] = z[i]+1;
        }

        int ans=0;

        for(int i=1; i<=Q; i++){
            int left = l[i]; int right = r[i];
            if( (left<=k[i]) && (k[i]<=right) ){
                ans += v[lengggggttthhh-k[i]];
            }
            
        }
        
        cout<<"Case #"<<caseno<<": "<<ans<<"\n";
        caseno++;

        delete[] x;
        delete[] y;
        delete[] z;
    }
	return 0;
}
