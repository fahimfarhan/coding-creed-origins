#include <bits/stdc++.h>

using namespace std;

class A950{
private:
    int ans,l,r,a;
public:
    A950(){
        scanf("%d %d %d",&l,&r,&a);
        if(l<r){
            if(r-l>a)l+=a;
            else{
                int temp = r-l;
                r=r +(a-temp)/2;
                l=r;
            }
        }
        else if(l>r){ 
            if(l-r>a){r+=a;}
            else{
                int temp = l-r;
                l=l+(a-temp)/2;
                r = l;
            }
        }
        else{ l+=(a/2); r+=(a/2);}
        //if(l<r) { ans = 2*l; }
        ans = min(l,r);
        ans=ans<<1;

        printf("%d\n",ans);
    }
    ~A950(){}
};
int main()
{
    A950 a950;
    return 0;
}