#include <bits/stdc++.h>

using namespace std;

class A131{
private:
    string s;
    int n;
public:
    bool isCapital(char c){
        if(c>='A' && c<='Z'){
            return true;
        }else return false;
    }

    bool isSmall(char c){

        if (c >= 'a' && c <= 'z')
        {
            return true;
        }
        else
            return false;
    }

    A131(){
        cin>>s;
        n = 'a'-'A';
        for(int i=0; i<s.size();i++){
            if(isCapital(s[i])){
                printf("%c",s[i]+n);
            }else if(isSmall(s[i])){
                printf("%c", s[i] - n);
            }else{
                printf("%c",s[i]);
            }
        }
        printf("\n");

    }
    ~A131(){}
};
int main()
{
    A131 a131;
    return 0;
}