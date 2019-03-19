#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
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
                int n;
                cin>>n;
                n=n%4;
                if( (n==0) || (n==3) ){ cout<<"0\n";    }
                else{   cout<<"1\n";    }
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