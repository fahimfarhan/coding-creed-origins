/*                                           When Panda is Life !
 
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
  */

#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d ",x)
#define pf(x) printf("%f\n",x)

class Soln{
private:
    int n, *v,*t, *r;
    vector<int> result;
public:
    Soln(){
        si(n);
        v = new int[n+1];
        t = new int[n+1];
        r = new int[n+1];
        r[0]=0; v[0]=0; t[0]=0;
        for(int i=1; i<=n; i++){ r[i]=0; }

        for(int i=01; i<=n; i++){
            si(v[i]);
        }
        for(int i=01; i<=n; i++){
            si(t[i]);
        }
        /*for(int i=01; i<=n; i++){
            //r[i] = max(r[i-1]-t[i],0)+max(v[i]-t[i],0);
            for(int j=1; j<i; j++){
                r[i]=r[i]+min(v[j],t[i]);
                v[j]=min(v[j]-t[i],0);
            }
        }*/
        /*for(int i=1; i<=n; i++){
            for(int j=1; j<i-1; j++){
                v[j]=min(0,v[j]-t[i]);
                r[i]+=min(v[j],t[i]);
            }
            r[i]+=min(v[i],t[i]);
            v[i]=min(0,v[i]-t[i]);
        }*/
        for(int i=1; i<=n; i++){
            for(int j=01; j<=i;j++){
                r[i]+=min(v[j],t[i]);
                v[j]=max(v[j]-t[i],0);
            }
        }

        for(int i=1; i<=n; i++){ pi(r[i]); }
        printf("\n");
    }
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}