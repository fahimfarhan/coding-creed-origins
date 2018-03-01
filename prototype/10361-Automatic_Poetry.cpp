#include <bits/stdc++.h>

using namespace std;

class Ap{
private:
    int n, pos1,pos2, pos3,pos4,pos5;
    string *s;
    string s1,s2,s3,s4;
public:
    Ap(){
        scanf("%d",&n);
        s = new string[2*n+1];
        for(int i=0; i<=2*n; i++){
            //cin>>s[i];
            getline(cin,s[i]);
        }
        for(int i=01; i<=2*n; i++){
            //cout<<i<<" "<<s[i]<<"\n";
            if( (i&1) == 1){

                pos1 = s[i].find("<");
                pos2 = s[i].find(">");
                pos3 = s[i].find("<", pos1+1);
                pos4 = s[i].find(">", pos2+1);
            
                s1=s[i].substr(pos1+1,pos2-pos1-1);
                s2=s[i].substr(pos2+1,pos3-pos2-1);
                s3=s[i].substr(pos3+1,pos4-pos3-1);
                s4=s[i].substr(pos4+1,s[i].size()-pos4-1);

                s[i].erase(pos1-0, 1);
                s[i].erase(pos2-1, 1);
                s[i].erase(pos3-2, 1);
                s[i].erase(pos4-3, 1);

                cout<<s[i]<<endl;
            }else{
                pos5 = s[i].find("...");
                s[i].erase(pos5, 3);
                s[i].insert(pos5,s3+s2+s1+s4);

                cout<<s[i]<<endl;
            }
        }

    }
    ~Ap(){
        if(!s)delete[] s;
    }
};

int main()
{
    Ap ap;
    return 0;
}