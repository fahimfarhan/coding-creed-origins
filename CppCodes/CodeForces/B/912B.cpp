#include <bits/stdc++.h>
using namespace std;

class B912{
private:
  int64_t n, k,ans; // int64_t
public:
    B912(){
        cin>>n>>k;//
        //scanf("%I64d %I64d",&n,&k);
        ans = 0;
        if(k==1){
            ans = n;
        }else{
            ans = 1;
            while(ans<=n){
                ans=ans*2;
            }
            ans = ans-1;
        }
        /*if(n==k){
            // that means she takes all of'em!
            for (int64_t i = 1; i <= n; i++)
            {    ans = ans ^ i; }
        }else if(k==1){
            ans = n;
        }
        else{
            int64_t temp = 0; //(int64_t)log2(n);
            int64_t num=n;
            while(true){
                if(num/2>0){
                    temp++;
                    num=num/2;
                }else break;

            }
            //cout<<"temp = "<<temp<<endl;
            for(int64_t i=0; i<k; i++){
                ans = ans << 1;
                ans = ans^1;
            }
            ans = ans<<(temp+1-k);
            
        }*/
        

        //printf("%I64d\n",ans);
        cout<<ans<<endl;

    }
    ~B912() {}
};

int main()
{
    B912 b912;
    return 0;
}