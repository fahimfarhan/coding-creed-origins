#include <bits/stdc++.h>

using namespace std;

class A131{
private:
    string s;
public:
    A131(){
        cin>>s;
        if(case1()){
            for(int i=0; i<s.length(); i++){
                cout<<(char)(s[i]-'A'+'a');
            }printf("\n");
        }
        else if(case2()){
            cout<<(char)(s[0]-'a'+'A');
            for(int i=1; i<s.length(); i++){
                cout<<(char)(s[i]-'A'+'a');
            }printf("\n");
        }
        else cout<<s<<"\n";
        
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

    ~A131(){}
};

int main()
{
    A131 a131;
    return 0;
}