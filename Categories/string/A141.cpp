#include <bits/stdc++.h>

using namespace std;

class A141{
private:
    string s1,s2,s3;
    
public:
    A141(){
        cin >> s1;
        cin >> s2;
        cin >> s3;

        s1 = s1+s2;
    //printf("%s\n",s1);
        //cout<<s1<<endl;
        sort(s1.begin(),s1.end());
        sort(s3.begin(),s3.end());
        //cout<<s1<<" "<<s3<<endl;
        if(s1 == s3){   printf("YES\n"); }
        else printf("NO\n");
    }
    ~A141(){    }
};
int main()
{
    A141 a141;
    return 0;
}