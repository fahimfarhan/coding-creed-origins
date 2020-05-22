#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

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
    int T,n;
    string s;
    int distanceFromNorth = 0;

    cin>>T;
    bool b = true;
    while(T--){
        cin>>n>>s;
        if( (distanceFromNorth == 0    ) && (s!="South") ){    b = false; break;  }
        else if( (distanceFromNorth == 0    ) && (s=="South") ) 
        {       distanceFromNorth+=n;  continue;   }
        
        if( (distanceFromNorth == 20000) && (s!="North") ){    b = false; break;    }
        else if( (distanceFromNorth == 20000) && (s=="North") )
        {       distanceFromNorth-=n; continue;   }

        if( (distanceFromNorth>0) && (distanceFromNorth< 20000) ){
            if(s=="North"){ distanceFromNorth-=n;  }
            else if(s=="South"){ distanceFromNorth+=n;  }
            else continue;
        }
    
    }

    if(b==false){   cout<<"NO\n";    }
    else {
        //cout<<distanceFromNorth<<"\n";
        if(distanceFromNorth==0){
            cout<<"YES\n";
        }else{  cout<<"NO\n";   }
    }

    return 0;
}
