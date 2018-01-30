#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class F630{
private:
    //int n;
    int64_t n,ans, nC5,nC6,nC7;
public:
    F630() {
        scanf("%I64d",&n);
        nC5 = n*(n-1)*(n-2)*(n-3)*(n-4)/120;
        nC6 = nC5*(n-5)/6;
        nC7 = nC6*(n-6)/7;
        ans  = nC5+nC6+nC7;
        printf("%I64d\n",ans);
        //cout<<ans<<endl;
    }
  ~F630() {}
};

int main()
{
    F630 f630;
    return 0;
}