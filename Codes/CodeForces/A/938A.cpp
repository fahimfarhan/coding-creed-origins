#include <bits/stdc++.h>

using namespace std;

class A938{
private:
    int n;
    int pos;
    string s;
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
    }

    void escape(){
        int j=pos+1;
        while(isVowel(s[j])){
            j++;
        }
        pos = j;
    }

    A938(){
        scanf("%d",&n);
        cin>>s;
        pos = 0;
        while(pos<n){
            printf("%c",s[pos]);
            if(!isVowel(s[pos])){
                pos++;
            }else{
                escape();
            }
        }
        printf("\n");

    }
    ~A938(){}
};

int main()
{
    A938 a938;
    return 0;
}
