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

bool isvowel(char ch){
    bool ret = false;
    if(ch =='a' || ch=='e'||ch=='i'||ch=='o'||ch=='u'){ ret = true; }
    return ret;
}

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

    string s1,s2;
    cin>>s1>>s2;

    if(s1.size() != s2.size()){
        cout<<"No\n"; exit(0);
    }
    int len = s1.size();
    bool b1, b2;
    for(int i=0; i<len; i++){
      b1 = isvowel(s1[i]); b2 = isvowel(s2[i]);

      if(b1 != b2){ cout<<"No\n"; return 0; }
    }
    cout<<"Yes\n";
  
  return 0;
}


