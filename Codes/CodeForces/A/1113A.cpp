#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


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

    int n,v, dis, price;
    cin>>n>>v;
    dis = n-1;

    price = 0;
    if(dis<=v){
        price = dis;
    }else{
        // v < dis
        int m=dis-v;
        price = v;
        for(int i=2; i<2+m; i++){
            price = price +i;
        }
    }

    cout<<price<<"\n";
  
  return 0;
}

