#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
class C478{
private:
    ll r,b,g,ans;
public:
  C478() {
    scanf("%I64d %I64d %I64d",&r,&b,&g);
    ll temp1 = (r+b+g)/3;
    ll temp2 = min(r+b,min(r+g,b+g));
    ans = min(temp1,temp2);
    printf("%I64d",ans);
  }
  ~C478() {}
};
int main()
{
    C478 c478;
    return 0;
}