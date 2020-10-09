#include <bits/stdc++.h>

using namespace std;

class A916
{
  private:
    int x, hh, mm, ans;
    int r;

  public:
    A916()
    {
        ans = 0;
        scanf("%d", &x);
        scanf("%d %d", &hh, &mm);

      
        while(true)// ((mm % 10) != 7)
        {
            if ( ((mm % 10) == 7) || ( (mm/10) == 7 ) || ((hh%10) == 7) || ((hh/10) == 7) )
            break; 
            
            mm = mm - x;
            ans++;
            if (mm < 0)
            {
                mm += 60;
                hh--;
            }
            if(hh<0){
                hh=23;
            }
        }
        printf("%d\n", ans);
        /*if(mm%10==7){
            printf("0\n");
            exit(0);
        }*/
    }
    ~A916() {}
};
int main()
{

    A916 a916;
    return 0;
}