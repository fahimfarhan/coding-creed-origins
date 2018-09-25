#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

class Soln{
private:
    int n;
public:
    Soln(){}
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int a,b;float h;
    cin>>b>>a;
    h = 2*a/b;
    /*float temp = h - (int)h;
    if( temp !=0){    h = (int)(h+1);}
    if(h*b/2 > a){   cout<<h<<"\n";     }
    else{      cout<<h+1<<"\n";   }
	*/
    while( (h*b/2) > a){   h--;    }
    while( (h*b/2) < a){   h++;    }
    
    // cout<<h<<"\n";
    printf("%d\n",(int)h);
    return 0;
}

/*
1 1000000

Expected Output
Download

2000000

*/