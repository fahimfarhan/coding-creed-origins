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
bool myAssert(int a[], int b[], int arraysize);
void setLPS();

int n,m;
vector<int> *g;
bool *isvisited;

string text, pattern;
int *lps;
int lpslen;
// longest proper prefix which is also suffix

bool myAssert(int a[], int b[], int arraysize){
    int len = arraysize;
    for(int i=0; i<len; i++){   if(a[i]!=b[i]) return false; }
    return true;
}

void setLPS(){
    // for(int i=0; i<)
}

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  text = "AABAACAADAABAABA"; pattern = "AABA";
  lpslen = text.size();

  lps = new int[lpslen];

  for(int i=0; i<lpslen; i++){ lps[i] = 0; }

  setLPS();

  if(!lps)delete[] lps;
  return 0;
}
