#include <bits/stdc++.h>

using namespace std;

class KCG494{
private:
    int count, flag;
    string s;
public:
    KCG494(){
        while(getline(cin,s)){
            count=0;
            flag=0;
            for(int i=0; i<s.length(); i++){
                if( (s[i]>='A'&&s[i]<='Z') || 
                (s[i]>='a'&&s[i]<='z')){
                    flag=1;
                }else{
                    count=count+flag;
                    flag=0;
                }
            }
            count+=flag;
            printf("%d\n",count);
        }
    }
    ~KCG494(){}
};
int main()
{
    KCG494 kcg494;
    return 0;
}
