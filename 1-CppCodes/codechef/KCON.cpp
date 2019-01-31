#include <bits/stdc++.h>

using namespace std;

class KCON{
private:
    int T,N,K, *A, minusCount;
    int64_t ans;
    vector<int> minusPos;
    void destruct()
    {
        if (!minusPos.empty())  minusPos.clear();
        if (!A)  delete[] A;
    }

  public:


    KCON(){
        scanf("%d",&T);
        while(T--)
        {
            ans = 0;
            scanf("%d %d",&N,&K);
            A = new int[N];
            for(int i=0; i<N; i++){
                scanf("%d",&A[i]);
                if(A[i]<0){minusPos.push_back(i);}
            }
            minusCount = minusPos.size();
            if(minusCount==0){
                for(int i=0; i<N; i++){
                    ans = ans+A[i];
                }
                ans=ans*K;
            }
            else if(minusCount==1){
                for(int i=0; i<minusPos[0];i++){
                    ans = ans+A[i];
                }

                for (int i = minusPos[0]+1; i <N ; i++)
                {
                    ans = ans + A[i];
                }
            }
            else if(minusCount==N){
                sort(A,A+N);
                ans = A[N-1];
            }
            else{
                int64_t temp=0;int64_t max=0;
                for (int i = 0; i < minusPos[0]; i++)
                {
                    temp = temp + A[i];
                }

                for (int i = minusPos[minusCount-1] + 1; i < N; i++)
                {
                    temp = temp + A[i];
                }
                if(temp>max) max = temp;

                for(int i=1; i<minusPos.size(); i++){
                    temp=0;
                    int index1 = minusPos[i-1];
                    int index2 = minusPos[i];

                    for(int j=index1+1; j<index2; j++){
                        temp = temp+A[j];
                    }
                    if (temp > max)  max = temp;
                }
                ans = max;
            }
            printf("%I64d\n",ans);
            destruct();
        }
    }
    ~KCON(){    destruct(); }
};
int main()
{
    KCON kcon;
    return 0;
}