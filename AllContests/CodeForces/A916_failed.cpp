#include <bits/stdc++.h>

using namespace std;

class A916{
private:
    int x, hh,mm, ans;
public:
    A916(){
        ans = 0;
        scanf("%d",&x);
        scanf("%d %d",&hh,&mm);
        while( (mm%10) != 7){
            mm = mm-x;
            ans++;
            if(mm<0){
                mm+=60;
                //hh--;
            }            
        }
        printf("%d\n",ans);
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