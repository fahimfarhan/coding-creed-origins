#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int T;
    cin>>T;
    // regex pattern1("[a-z]+(ch|x|s|o)");
    while(T--){
        string s, t;
        cin>>s;
        int l = s.length();
        if(s[l-2]=='c' && s[l-1]=='h' ){
            t = s+"es";
            
        }else if(s[l-1] == 'x' || s[l-1] == 's' || s[l-1] == 'o' ){
            t = s+"es";
            
        }else if(s[l-2]=='f' && s[l-1]=='e' ){
            t = s.substr(0,l-2)+"ves";
        }else if( s[l-1]=='f' ){
            t = s.substr(0,l-1)+"ves";
        }else if( s[l-1]=='y' ){
            t = s.substr(0,l-1)+"ies";
        }else{
            t = s+"s";
        }
        cout<<t<<"\n";

    }
	return 0;
}


/*
java -jar dbpedia-spotlight-1.0.0.jar /home/fahimfarhan/Codes/Thesis-Codes/KnowledgeGraph/Ignore/en_2+2 http://localhost:2222/rest

*/