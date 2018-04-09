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

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%f\n",x)

class Soln{
private:
    int n,carry;
    string s, n1,n2,result;
public:
    Soln(){
        while(getline(cin,s)){
            //s1: take inputs
            int pos = s.find(',');
            n1 = s.substr(0,pos);
            n2 = s.substr(pos+1);

            //cout<<n1<<" "<<n2;
            //s2: reverse the strs
            /*n1.reverse();
            n2.reverse();
            */
            reverse(n1.begin(), n1.end());
            reverse(n2.begin(), n2.end());
            int smallLen=0;
            if(n1.length()<n2.length()){ smallLen = n1.length(); }
            else{ smallLen = n2.length(); }
        
            result = "";
            int i=0;
            carry=0;
            while(i<smallLen){
                i++;
                n = n1[n1.length()-i]-'0' + n2[n2.length()-i]-'0'+carry;
                //cout<<"n= "<<n<<endl;
                carry = n/10;
                n=n%10;
                //result = result+(char)n+'0';
                string lastLetter(1,(char)n+'0');
                result = result+lastLetter;
                //cout<<"result= "<<result<<endl;
            }

            if(n1.length()<n2.length()){
                int i=0; 
                while(i<n2.length()-smallLen){
                    i++;
                    n = n2[n2.length()-i]-'0'+carry;
                    carry = n/10;
                    n=n%10;
                    //result = result+(char)n+'0';
                string lastLetter(1,(char)n+'0');
                result = result+lastLetter;

                }
                
            }else{
                int i=0; 
                while(i<n1.length()-smallLen){
                    i++;
                    n = n1[n1.length()-i]-'0'+carry;
                    carry = n/10;
                    n=n%10;
                    //result = result+(char)n+'0';
                string lastLetter(1,(char)n+'0');
                result = result+lastLetter;
                }
            }
            if(carry){ 
                //result = result+(char)carry+'0';
                                string lastLetter(1,(char)carry+'0');
                result = result+lastLetter; 
            }

            //strp 3: remove leading zeros!
            pos = 0;
            bool b=false;
            for(int i=0; i<result.length(); i++){
                if(result[i]!='0'){  pos = i; break;  }
            }
            //for(int i=0; i<pos; i++){ result.erase(i); }
            
            result = result.substr(pos);
            cout<<result<<endl;
        }
    }
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}