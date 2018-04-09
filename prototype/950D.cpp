#include <bits/stdc++.h>

using namespace std;

class D950{
private:
    long long n,q,i;
public:
    D950(){
        //scanf("%I64d I64d",&n,&q);
        //printf("%RId64 RId64",n,q);
        cin>>n>>q;
        while(q--){
            cin>>i;
            //scanf("%I64d",&i);
            while(i%2==0){
                //i = i + n -(i/2);
                i = n+(i>>1); // i = n+i/2;
            }
            i = (i>>1)+1;
            cout<<i<<endl;
            //printf("%I64d\n",i);
        }
    }
    ~D950(){}
};

int main()
{
    D950 d950;
    return 0;
}


/*#include <bits/stdc++.h>
using namespace std;
long long int n,q,i;
int main()
{
  cin>>n>>q;
  while(q--)
    {
      cin>>i;
      while(i%2==0)i+=n-(i/2);
      cout<<i/2+1<<endl;
    }
  return 0;
}*/