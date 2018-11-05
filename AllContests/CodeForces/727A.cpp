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

	int n,a,b;
    stack<int> s;

    cin>>a>>b;
    bool f = true;
    s.push(b);
    while(true){
        if(a==b){   f=true; break; }
        if(b<a){    f=false; break; }
        if( (b%2) == 0 ){
            // b is even 
            b = b/2;
            s.push(b);
        }else if( (b%10) == 1 ){
            b = (b-1)/10;
            s.push(b);
        }else{
            f = false;break;
        }
    }
    if(f){
        cout<<"YES\n";
        cout<<s.size()<<"\n";
        while(!s.empty()){
            int x = s.top(); s.pop();
            cout<<x<<" ";
        }cout<<"\n";

    }else{
        cout<<"NO\n";
    }
	return 0;
}
