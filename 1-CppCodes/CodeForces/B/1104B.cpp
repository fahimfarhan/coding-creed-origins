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

    string str;
    stack<char> s;
    bool p = true;
    cin>>str;
    //s.push(str[0]);
    for(int i=0; i<str.size(); i++){
        if(s.size()==0){
            s.push(str[i]);
        }
        else if(s.top() == str[i]){
            s.pop();
            p = !p;
        }else{  s.push(str[i]);   }
    }
    if(p){ cout<<"No\n"; }
    else{ cout<<"Yes\n";  }

  
  return 0;
}

