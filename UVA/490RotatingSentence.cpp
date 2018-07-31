#include <bits/stdc++.h>

using namespace std;

class RS490{
private:
    string s[101]; int line,longest;
public:
    RS490(){
        line = 0;
        longest=0;
        while(getline(cin, s[line])){
            if(s[line].length()>longest){
                longest = s[line].length();
            }
            line++;
        }

        for(int i=0; i<longest; i++){
            for(int j=line-1; j>=0; j--){
                if(i<s[j].length()){
                    cout<<s[j][i];
                }else{
                    cout<<" ";
                }
            }
            cout<<"\n";
        }
    }
    ~RS490(){}

};

int main()
{
    RS490 rs490;
    return 0;
}