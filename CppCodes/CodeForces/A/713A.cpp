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

int *mycount, mysize;

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

    mysize = 1<<18;

    cout<<mysize<<"\n";
    

    mycount = new int[mysize+1];

    int T;
    cin>>T;
    string  s;
    char q;
    int num;
    while(T--){
      cin>>q>>s;

      num =0; 
      for(int i=0; i<s.size(); i++){  num = (num<<1) | ((s[i]-'0')&1) ; }
        
      if(q=='+'){
        mycount[num]++;
      }else if(q=='-'){
        mycount[num]--;
      }else if(q=='?'){
        cout<<mycount[num]<<"\n";   
      }
    }

    if(!mycount)delete[] mycount;
    return 0;
}
