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

    short a[3];
    for(short i=0; i<3; i++){     cin>>a[i];    }

    sort(a,a+3);

    if(a[0]+a[1]>a[2]){ cout<<"0\n";    }
    else
    {      cout<<(a[2]-(a[0]+a[1])+1)<<"\n";    }
  
  return 0;

}


