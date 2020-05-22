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
    int cnt[5];
    for(int i=1; i<5; i++){     cin>>cnt[i];    }
    //for(int i=0; i<5; i++){     cout<<cnt[i]<<" ";    } cout<<"\n";
    
    bool b=false;

    if( (cnt[1]==0) && (cnt[3]==0) && (cnt[4]==0) ){
        b = 1;
      //  cout<<"1\n";
    }else if( (cnt[1]==cnt[4]) && (cnt[4]!=0) ){
        b=1;
        //cout<<"2\n";
    }else if( (cnt[1]==cnt[4]) && (cnt[4]==0) && (cnt[3]!=0) ){
        b=0;
        //cout<<"3\n";
    }else{
        b=0;
        //cout<<"4\n";
    }

    cout<<b<<"\n";
    return 0;
}
