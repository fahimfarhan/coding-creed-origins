#include <bits/stdc++.h>

using namespace std;

class B499{
private:
    int m,n;
    map<string, string> mp;
    string s1,s2;
    string *s;
public:
    B499(){
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++){
            cin>>s1>>s2;
            mp[s1]=s2;
        }
        s = new string[n];
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        for(int i=0; i<n; i++){
            s1 = mp[s[i]];
            if(s1.length()<s[i].length()){
                cout<<s1<<" ";
            }else cout<<s[i]<<" ";
        }
        //cout<<endl;
        printf("\n");
    }

    ~B499(){
        if(!s)delete []s;
    }
};

int main()
{
    B499 b499;
    return 0;
}