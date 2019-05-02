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

    int n,d,m,x,y;
    bool b1,b2;
    cin>>n>>d;

    cin>>m;
    while(m--){
        cin>>x>>y;
        if((d<=(x+y))&&((x+y)<=(2*n-d))){    b1=true;  }else{   b1=false;  }
        if(( (-d) <=(x-y))&&((x-y)<=(d))){   b2=true;  }else{   b2=false;  }

        if(b1&&b2){ cout<<"YES\n";   }
        else{       cout<<"NO\n" ;   }
        
    }

    
    return 0;
}
