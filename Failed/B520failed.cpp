#include <bits/stdc++.h>

using namespace std;

class B520{
private:
    int n,m,ans;
public:
    B520(){
        ans = 0;
        scanf("%d %d",&n,&m);
        if(m<n){
            ans = n-m;
        }else{
            //ans = n;
            while(n<m){
                n=n*2;
                ans++;
            }
            
            ans = ans + n - m;
        }
        printf("%d\n",ans);
    }
    ~B520() {}
};
int main()
{
    B520 b520;
    return 0;
}