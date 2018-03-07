#include <bits/stdc++.h>

using namespace std;

class C946{
private:
    string s;
    char c;
    int n;
    bool b;
public:
    C946(){
        b=true;
        c = 'b';
        cin>>s;
        n = s.length();
        /*if(c == s[0]){
            cout<<"ok";
        }*/
        /*if(n<26){
            b = false;           
        }else{
            */
            /*for(int i=0; i<n; i++){
                if(s[])
            }*/
            int i=0;
            // find 1st a
            while(1){  if(s[i]=='a')break; i++;  }
            for(int j=i+1; j<n; j++){
                //cout<<c<<endl;
                if(s[j]<=c)
                { 
                    s[j]=c; 
                    c=c+1;
                }
                //j++;
            }
            if(c<'z'){ b=false; }
        //} //end else
        //cout<<c<<endl;

        if(b){
            cout<<s<<endl;
        }else{
            cout<<"-1\n";
        }
    }
};
int main()
{
    C946 c946;
    return 0;
}