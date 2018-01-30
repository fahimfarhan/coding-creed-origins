#include <bits/stdc++.h>
using namespace std;

class D914{
private:
    int n,l,r,x,q,*a, f, I, y;
    int xprev;
    vector<int> v;
public:
    D914(){
        xprev = -1;
        scanf("%d",&n);
        a = new int[n+1];
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        scanf("%d", &q);
        for(int i=0; i<q; i++){
            scanf("%d",&f);
            if(f==1){
                scanf("%d %d %d",&l,&r,&x);
                if(x!=xprev)yo();
                else yo1();
            }else if(f==2)
            {
                scanf("%d %d", &I, &y);
                a[I] = y;
            }
        }
    }

    void yo1(){
        int count=0;
        if(a[I]%x){count++;}

        for(int i=0;i<v.size();i++){
            int pos = v[i];
            if(a[pos]%x){
                count++; 
            }
        }
        if (count < 2) printf("YES\n");
        else  printf("NO\n");
    }

    void yo(){
        v.clear();
        int count=0;
        for(int i=l; i<=r; i++){
            if(a[i]%x){count++; v.push_back(i);}
            if(count>1){ printf("NO\n"); break;}
        }
        if(count<2) printf("YES\n");
        //else  printf("NO\n");
    }

    ~D914() {if(!a)delete[] a;}
};


int main(int argc, char const *argv[])
{
    /* code */
    D914 d914;
    return 0;
}