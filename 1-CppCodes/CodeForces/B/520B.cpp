#include <bits/stdc++.h>

using namespace std;

class B520{
private:
    int n,m,count;
public:
    B520(){
        scanf("%d %d",&n,&m);
        count = 0;
        while(m!=n){
        if(m>n){
            if (m % 2 == 0)
                {
                    m = m / 2;
                }
                else
                {
                    m++;
                    //count++;
                }
                //count++;
        }
            else
            { //m<n
                m++;
                
            }
            count++;
        }
        printf("%d\n",count);
        
    }
    ~B520() {}
};
int main()
{
    B520 b520;
    return 0;
}