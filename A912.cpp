#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class A912{
private:
    int64_t a,b,x,y,z;
    int64_t yellow, green, blue, ans;

  public:
    A912(){
        //scanf("%I64d %I64d",&a,&b);
        //scanf("%I64d %I64d %I64d", &x, &y,&z);
        ans = 0;
       
        cin>>a>>b;
        cin>>x>>y>>z;
        yellow = 2 * x + y;
        blue = y + 3 * z;

        if(a<yellow){ans=ans+yellow-a;}
        if(b<blue){ans = ans+blue-b;}
        //ans = yellow + blue;

        cout<<ans<<endl;
        //printf("%I64d",ans);

    }

    ~A912()
    {    }
};
int main()
{
    A912 a912;
    return 0;
}