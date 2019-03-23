#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int *phi; bool *mark;
int N;
    
void seivephi(int n){
    // initialization 
    for(int i=0; i<=n; i++){    phi[i]=i; mark[i]=0; }

    phi[1]  = 1;
    mark[1] = 1;

    for(int i=2; i<=n; i++){
        if(!mark[i]){
            for(int j=i; j<=n; j+=i){
                mark[j]=1; 
                phi[j] = phi[j]*(i-1)/i;
            }

        }
    }

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

    cin>>N;

    phi = new int[N+1]; mark = new bool[N+1];
    seivephi(N);

    cout<<phi[N]<<'\n';
    if(!phi)delete[] phi; 
    if(!mark)delete[] mark;
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/