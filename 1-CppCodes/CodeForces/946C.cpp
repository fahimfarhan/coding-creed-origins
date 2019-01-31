#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%f\n",x)

class Soln{
private:
    int n;
    string s;
    char c;
public:
    Soln(){
        c = 'a';
        cin>>s;

        n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]<=c){ s[i]=c; c++; }
            if(c==('z'+1)) break;     
        }

        if(c==('z'+1)){ cout<<s<<endl; }
        else{  printf("-1\n"); }
    }
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}