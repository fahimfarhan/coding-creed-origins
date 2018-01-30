#include <bits/stdc++.h>

using namespace std;

class MAXSC{
private:
    int T, N, **A;
    int64_t ans;
public:
    void destroy(){
        for (int i = 0; i < N; i++)
        {   if (!A[i])  delete[] A[i];  }
        if (!A)  delete[] A;
    }
    void create(){
        A = new int*[N];
        for(int i=0; i<N;i++){
            A[i] = new int[N];
        }
    }
    MAXSC(){
        scanf("%d",&T);
        while(T--)
        {
            scanf("%d", &N);
            create();
            ans = 0;
            for(int i=0;i<N;i++){
                for(int j=0; j<N;j++){
                    scanf("%d",&A[i][j]);
                }
            }

            for (int i = 0; i < N; i++){    sort(A[i],A[i]+N);}
            //int i,j; i=N-1;
            //j = N - 1;
            //int E[2];
            ans = A[N-1][N-1];
            int E = ans;
            //int n=N-1;
            bool b = true;
            for(int i=N-2; i>=0;i--){
                int j=N-1;
                while(A[i][j]>E){j--;}
                if(j<0){b = false; break;}
                E = A[i][j];
                ans+=E;
            }

            if(b){  printf("%I64d\n",ans); }
            else{   printf("-1\n"); }
            
            destroy();
        }
    }
  ~MAXSC(){
      destroy();
  }
}; 

int main()
{
    MAXSC _MAXSC;
     return 0;
}