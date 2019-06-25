#include <bits/stdc++.h>

using namespace std;

class CHCOINSG
{
  private:
    int T, n;
public:
  CHCOINSG() {
      scanf("%d",&T);
      while(T--){
          scanf("%d",&n);
          if(n==6) printf("Misha\n");
          else printf("Chef\n");
      }
  }
};
int main()
{
    CHCOINSG chcoinsg;
    return 0;
}