#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n, m;
    double *g, *a,*b;

public:
    Soln(){
        scanf("%d %d",&n,&m);
        //cout<<n<<m;
        g = new double[n];
        a = new double[n];
        b = new double[n];
        for(int i=0; i<n; i++){
            scanf("%lf %lf",&a[i],&b[i]);
            //cin>>a[i]>>b[i];
            //g[i] = a/b;
        }
        for(int i=0; i<n; i++){
            g[i]=a[i]/b[i];
        }
        sort(g,g+n);

        double ans=g[0]*m;
        printf("%0.8f\n",ans);
        //cout << std::setprecision(9) << g[0]*m << '\n';
    }
    ~Soln(){
        if(!g) delete[] g;
        if(!a) delete[] a;
        if(!b) delete[] b;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}