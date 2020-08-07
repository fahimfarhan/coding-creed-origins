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
  string s,t;
  cin>>t;
  s = "";
  bool xcase = true;
  if(t.size()%2 ==0 ){ xcase = true; } // last pos == r8 most char
  else{ xcase = false; } // last char == left most char 
  list<char> l;
  for(int i=0; i<t.size(); i++){
      l.push_back(t[i]);
  }
  //cout<<"l.size() "<<l.size()<<"\n";
char c;
    stack<char> st;
    int i=0;
  //for(int i=0; i<l.size(); i++)
  while(!l.empty()){
      
      if(xcase == true){ c = l.back(); l.pop_back();
       }
      else if(xcase == false){  c = l.front(); l.pop_front();
       }
      xcase = !xcase;
    //  cout<<c<<" "<<i<<"\n";
        st.push(c);
  }
//cout<<"st.size() "<<st.size()<<"\n";
  while(!st.empty()){
      c = st.top();
      st.pop();
      cout<<c;
  }
  cout<<"\n";

  
  return 0;
}
