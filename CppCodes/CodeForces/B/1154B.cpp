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

    int avg1,avg2,a, n,D;
    set<int> s;

    cin>>n;
    int minimus =INT_MAX;
    int maximus = 0;
    for(int i=0; i<n; i++)
    { cin>>a; maximus = max(maximus, a); minimus = min(minimus, a); s.insert(a);  }

    if(s.size() == 2){
        D = maximus - minimus;
        if( (D&1)==1 )
            cout<<D<<"\n";
        else{
            D = (D>>1);
            cout<<D<<"\n";
        }
             
        return 0;
    }

    D = ( maximus - minimus );
    if( (D&1) == 1){
        cout<<"-1\n";
    }else{
        D = (D>>1);
        avg1 = minimus + D;
        avg2 = maximus - D;

        s.insert(avg1); s.insert(avg2);
        if(s.size() >3 ){   cout<<"-1\n";   }
        else{
            cout<<D<<"\n";
        }
    }


    return 0;
}
