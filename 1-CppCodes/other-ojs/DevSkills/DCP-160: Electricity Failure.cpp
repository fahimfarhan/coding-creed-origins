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

   // Target sequence 
    string s = "f(3,2)"; 
  
    // An object of regex for pattern to be searched 
    regex r("f([0-9]+,[0-9]+)"); //r("Geek[a-zA-Z]+"); 
  
    // flag type for determining the matching behavior 
    // here it is for matches on 'string' objects 
    smatch m; 
  
    // regex_search() for searching the regex pattern 
    // 'r' in the string 's'. 'm' is flag for determining 
    // matching behavior. 
    regex_search(s, m, r); 
  
    // for each loop 
    for (auto x : m) 
        cout << x << " "; 
  
    return 0; 

  
  return 0;
}
