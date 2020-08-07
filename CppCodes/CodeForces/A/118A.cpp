#include <bits/stdc++.h>

using namespace std;

class A118{
private:
    string s;
    vector<char> v;
public:
    bool isConsonant(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u' || c=='y'){
            return false;
        }else return true;
    }
    A118()  {
        cin>>s;
        for(int i=0; i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]+'a'-'A';
            }
        }

        for(int i=0; i<s.length();i++){
            if(isConsonant(s[i])){
                v.push_back(s[i]);
            }
        }

        for(int i=0; i<v.size();i++){
            printf(".%c",v[i]);
        }printf("\n");

        //cout<<s<<endl;
    }
    ~A118() {}
};
int main()
{
    A118 a118;
    return 0;
}