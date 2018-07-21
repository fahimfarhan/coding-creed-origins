#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long 


int main(int argc, char const *argv[])
{
	/* code */
	int n,m, ans;
    int *a,b;

    si(n); si(m);

        a = new int[n];
        for(int i=0; i<n; i++){
            si(a[i]);
        }

        sort(a,a+n);

        for(int i=0; i<m; i++){
            si(b);
            ans = upper_bound(a,a+n, b)-a;
            printf("%d ",ans);
        }
        printf("\n");

        if(!a) delete[] a;

	return 0;
}
