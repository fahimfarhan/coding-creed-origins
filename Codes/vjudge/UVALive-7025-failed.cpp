#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)
#define SIZE 200000005
#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int T,N,*x,*y;
int x1,y_1,x2,y2;


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

    cin>>T;
    x = new int[SIZE];
    y = new int[SIZE];

    for(int i=0; i<SIZE; i++){  x[i]=0; y[i]=0; }

    while(T--){
        cin>>N;
        
        for(int i=0; i<SIZE; i++){  x[i]=0; y[i]=0; }       
        
        int x_min=INT_MAX, x_max=0, y_min=INT_MAX, y_max=0;
        for(int i=0; i<N; i++){ 
            cin>>x1>>y_1>>x2>>y2;
            x1+=100000000;
            x2+=100000000+1;
            y_1+=100000000;
            y2+=100000000+1;

            x_min = min(x_min, x1);
            x_max = max(x_max, x2);
            //y_min = min(y_min, y1);
            if(y_1<y_min){ y_min=y_1;    }
            
            y_max = max(y_max, y2);
            x[x1]+=1; 
            x[x2]-=1;

            y[y_1]+=1;
            y[y2]-=1;
        }

        int maximus, maximusX=0, maximusY=0;

        for(int i=x_min; i<x_max; i++){
            x[i]+=x[i]+x[i-1];
            //y[i]=y[i]+y[i-1];

            maximusX = max(maximusX,x[i]);
            //maximusY = max(maximusY,y[i]);
        }

        for(int i=x_min; i<x_max; i++){
            //x[i]+=x[i]+x[i-1];
            y[i]=y[i]+y[i-1];

            //maximusX = max(maximusX,x[i]);
            maximusY = max(maximusY,y[i]);
        }

        maximus = min(maximusX,maximusY);

        cout<<maximus<<"\n";

    }
    if(!x)delete[] x;
    if(!y)delete[] y;

    return 0;
}
