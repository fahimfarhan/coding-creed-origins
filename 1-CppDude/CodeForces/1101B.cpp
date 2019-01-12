#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
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

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    string s;
    cin>>s;
    int left=-1, right=-1, col1=-1, col2=-1, midval = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '['){
            left = i; break;
        }
    }
    if(left == -1){ cout<<"-1\n";   return 0; }
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == ':' && i > left){
            col1 = i; break; 
        }
    }
        if(col1 == -1){ cout<<"-1\n";   return 0; }
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == ']' && i > left){
            right = i; break; 
        }
    }
        if(right == -1){ cout<<"-1\n";   return 0; }
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == ':' && i<right && i>col1){
            col2 = i; break; 
        }
    }
        if(col2 == -1){ cout<<"-1\n";   return 0; }

  //if(left == -1 || right == -1 || col1 == -1 || col2 == -1){
    //  cout<<"-1\n";  
  //}else
  {
      for(int i=col1; i<=col2; i++){
          if(s[i] == '|'){  midval++; }
      }
      cout<<(midval+4)<<"\n";
  }
  return 0;
}
