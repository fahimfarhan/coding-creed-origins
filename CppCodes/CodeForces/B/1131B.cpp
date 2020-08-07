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

    int n, a,b,x,y, maximus, minimus, count, temp;
    cin>>n;
    a = 0; b = 0;
    count = 1;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        maximus = max(a,b);
        minimus = min(x,y);
        //if(maximus <= minimus){     count+=(minimus-maximus);   }
        //count+=abs(minimus-maximus);
        if(a!=b){   temp=1; }else{  temp=0; }

        count+=max(0, minimus-maximus+temp);
        
        a = x; b=y;
    }
   
    cout<<count<<"\n";
  return 0;
}


