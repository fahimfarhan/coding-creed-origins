#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
class B489{
private:
    int n,m, *a,*b, ans;

public:
    B489(){
        //cin>>n;
        //scanf("%d", &n);
        
        sd(n);
        a = new int[n];
        for(int i=0; i<n; i++){
            sd(a[i]);
        }
    
        sd(m);
        b = new int[m];
        for (int i = 0; i < m; i++)
        {
            sd(b[i]);
        }
        sort(a, a + n);
        sort(b,b+m);
        ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (abs(a[i] - b[j]) < 2)
                {
                    ans++;
                    b[j] = -1;
                    break;
                }
            }
        }

    printf("%d\n",ans);

    }
    ~B489() { if(!a)delete[] a; if(!b)delete[] b; }
};
int main()
{
    B489 b489;
    return 0;
}