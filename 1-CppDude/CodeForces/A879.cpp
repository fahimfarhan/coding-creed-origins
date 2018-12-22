#include <bits/stdc++.h>

using namespace std;

class A879{
private:
    int ans;
    int s,d,n;
public:
    A879(){
        ans = 0;
        scanf("%d",&n);
        //scanf("%d %d",&s,&d);
        //ans = s;
        for(int i=0; i<n; i++){
            scanf("%d %d", &s, &d);
            if(s>ans){ ans = s; }
            else{
                int m = 1 + (ans - s) / d;
                ans = s + m * d;
            }
            
        }

        printf("%d\n",ans);
    }
    ~A879() {}
};
int main()
{
    A879 a879;
    return 0;
}