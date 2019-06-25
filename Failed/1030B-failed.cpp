#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);

int n,d,m,*x,*y, a,b;
    
vector<int> *g;
bool *isvisited;

double getDistance(int x3,int y3, int p1, int p2){
    double ret=0;
    int x1 = x[p1], y1 = y[p1], x2=x[p2], y2=y[p2]; 

    double m = (1.0*(y1-y2))/(x1-x2);

    double x4, y4;
    x4 = (m/(m*m+1))*(y3-y1+m*x1+x3/m);
    y4 = y1+m*(x4-x1);

    ret = (x3-x4)*(x3-x4) + (y3-y4)*(y3-y4);
    ret = sqrt(ret);
    return ret;
}

double getLength(int p1,int p2){
    double ret=0;
    ret = (x[p1]-x[p2])*(x[p1]-x[p2]) + (y[p1]-y[p2])*(y[p1]-y[p2]);
    ret = sqrt(ret);

    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    x = new int[4]; y=new int[4];
    cin>>n>>d;
    x[0] = 0; y[0]=d; 
    x[1] = d; y[1]=0;
    x[2] = n; y[2] = n-d;
    x[3] = n-d; y[3]=n;

    cin>>m;
    double dis[4];

    double d1, d2;
    d1 = getLength(0,3);
    d2 = getLength(0,1);
    while(m--){
        cin>>a>>b;
        dis[0] = getDistance(a,b,0,3);
        dis[1] = getDistance(a,b,1,2);

        dis[2] = getDistance(a,b,0,1);
        dis[3] = getDistance(a,b,2,3);

        if((dis[0]+dis[1]>d2)||(dis[2]+dis[3]>d1)){    cout<<"NO\n";   }
        else{  cout<<"YES\n";  }
        
    }

    delete[] x; delete[] y;
    return 0;
}
