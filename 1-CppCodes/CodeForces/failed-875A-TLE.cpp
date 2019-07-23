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

    bool b = false;
    int n,x, count=0, sum=0;
    vector<int> v;
    cin>>n;

    int maximus = max(1,n-81);
    for(int i=maximus; i<=n; i++){
        x = i;
        sum = x;
        while(x>0){
            sum = sum+(x%10); x = x/10;
        }
        x = i;
        if(sum==n ){
            count++; v.push_back(x);
        }

    }
    //if(!count){ cout<<"0\n";    }
    //else{
        cout<<count<<"\n";
        for(int i=0; i<count; i++){ cout<<v[i]<<"\n";     }
    //}

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/