#include <bits/stdc++.h>

using namespace std;


#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);


int main()
{
    int T, N, K;
    si(T);
    while(T--){
        si(N); si(K);
        //ll p1,p2, A1,B1,C1,M1;
        //ll h1,h2, A2,B2,C2,M2;
        //ll x1,x2, A3,B3,C3,M3;
        //ll y1,y2, A4,B4,C4,M4;

        ll *p,*h,*x,*y,*A,*B,*C,*M;
        p = new ll[N+1];
        h = new ll[N+1];
        x = new ll[N+1];
        y = new ll[N+1];
        A = new ll[4+1];
        B = new ll[4+1];
        C = new ll[4+1];
        M = new ll[4+1];

        sll(p[1]);sll(p[2]);sll(A[1]);sll(B[1]);sll(C[1]);sll(M[1]);
        sll(h[1]);sll(h[2]);sll(A[2]);sll(B[2]);sll(C[2]);sll(M[2]);
        sll(x[1]);sll(x[2]);sll(A[3]);sll(B[3]);sll(C[3]);sll(M[3]);
        sll(y[1]);sll(y[2]);sll(A[4]);sll(B[4]);sll(C[4]);sll(M[4]);
        
        for(int i=3; i<=N; i++){
            p[i] = (A[1]*p[i-1])%M[1]+(B[1]*p[i-2])%M[1]+C[1]%M[1]+1;
            h[i] = (A[2]*h[i-1])%M[2]+(B[2]*h[i-2])%M[2]+C[2]%M[2]+1;
        }

        for(int i=3; i<=K; i++){
            x[i] = (A[3]*x[i-1])%M[3]+(B[3]*x[i-2])%M[3]+C[3]%M[3]+1;
            y[i] = (A[4]*y[i-1])%M[4]+(B[4]*y[i-2])%M[4]+C[4]%M[4]+1;
        }

        for(int i=1; i<=N; i++){
            cout<<"pi: "<<p[i]<<", hi: "<<h[i]<<"\n";
        }

        /*********************/
        delete[] p; delete[] h; delete[] x; delete[] y; delete[] A;
        delete[] B; delete[] C; delete[] M;
    }



    return 0;
}