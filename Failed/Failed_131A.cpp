#include <bits/stdc++.h>

#define CAPS true 
#define LOCK false
using namespace std;

class A131{
private:
    string s;
public:
    A131(){
        cin>>s;
        if(case1() || case2()){  printf("Caps\n");  }
        else if(case3() || case4()){    printf("Lock\n");   }
        else{   cout<<s<<"\n";  }
    }

    bool case1(){
        // all letters capital
        for(int i=0; i<s.length(); i++){
            if(!(s[i]>='A' && s[i]<='Z') )
                return false;
        }
        return true;
    }
    bool case2(){
        //1st small rest caps
        bool b = true;
        if(!(s[0]>='a' && s[0]<='z'))return false;
        for(int i=01; i<s.length(); i++){
            if(!(s[i]>='A' && s[i]<='Z') )
                return false;
        }
        return true;
    }

    bool case3(){
        // all letters capital
        for(int i=0; i<s.length(); i++){
            if(!(s[i]>='a' && s[i]<='z') )
                return false;
        }
        return true;
    }


    bool case4(){
        //1st small rest caps
        bool b = true;
        if(!(s[0]>='A' && s[0]<='Z'))return false;
        for(int i=01; i<s.length(); i++){
            if(!(s[i]>='a' && s[i]<='z') )
                return false;
        }
        return true;
    }

    ~A131(){}
};


int main()
{
    A131 a131;
    return 0;
}