#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
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

  int T;
  cin>>T;
  ll A,B,N, Q, count;
  string s;
  for(int i1=0; i1<T; i1++){
    cin>>A>>B;
    cin>>N;
    //A=A+1;
    count = N;
    bool flag = false;
    for(int i=0; i<count; i++){
      Q = (A+B)/2;
      cout<<Q<<"\n";
      cout << flush;
      //fflush(stdout);
      cin>>s;
      if(s=="TOO_SMALL"){
        A = Q;
      }else if(s == "TOO_BIG"){
        B=Q;
      }else if(s == "CORRECT"){
        flag = true;
        break;
      }else if(s=="WRONG_ANSWER"){
        exit(0);
      }
    }
    if(flag == false){  exit(0); }

  }
  
  return 0;
}


