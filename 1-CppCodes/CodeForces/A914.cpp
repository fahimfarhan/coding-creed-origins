#include <bits/stdc++.h>

using namespace std;

class A914{
private:

public:
    int n;
    int a, ans;
    A914()
    {
        ans = INT_MIN;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            if (a < 0 && a > ans)
            {
                ans = a;
            }
            else
            {
                if (!isPerfectSquare(a) && a > ans)
                {
                    ans = a;
                }
            }
        }
        
        printf("%d\n",ans);
    }
    bool isPerfectSquare(int x){
        int y = sqrt(x);
        if(x == y*y) return true;
        return false;
    }
    ~A914()
    {    }
};
int main()
{
    A914 a914;
    return 0;
}