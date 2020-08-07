#include <bits/stdc++.h>
using namespace std;

int main()
{

     ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    long long int t,n,c,sum,r,d;
    cin>>t;
    while (t--)
    {
        cin>>n;
        d=n;
        c=0;
        while (1)
        {
            sum=0;
            while (d>0)
            {
                r=d%10;
                sum=sum*10+r;
                d=d/10;
            }
            if (n==sum)
                break;
            else
            {
                d=sum+n;
                n=d;
                c++;
            }
        }
        cout<<c<<" "<<n<<"\n";
    }
    return 0;
}
