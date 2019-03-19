#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


namespace Start{
    class Start{
        private:
        // int n,m;
        vector<int> *g;
        bool *isvisited;
        public:
            Start(){
                int n,m, a[6];
                a[0] = 0; a[5]=0;
                cin>>n;
                for(int i=0; i<n; i++){
                    cin>>m;
                    a[m]++;
                }
                if(a[0]==0){
                    cout<<"-1\n";
                    exit(0);
                }

                else if( a[5]<9){
                    cout<<"0\n";
                }else{
                    m = a[5]/9;
                    m=m*9;
                    for(int i=0; i<m; i++){    cout<<"5"; }
                    m=a[0];
                    for(int i=0; i<m; i++){ cout<<"0";  }
                    cout<<"\n";
                }
            }
            ~Start(){}
    };
}



int main(int argc, char const *argv[])
{
    /* code */
    /* Soln soln */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Start::Start *s = new Start::Start();

    if(!s)delete[] s;

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/