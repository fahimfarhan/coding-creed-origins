#include <bits/stdc++.h>

using namespace std;

class A550{
private:
    string s;
    //int pos1,pos2,pos,pos4;
    int pos[4];
    bool b;
public:
    A550(){
        cin>>s;
        pos[0] = s.find("AB");
        pos[1] = s.find("AB", pos[0]+2);
        pos[2] = s.find("BA");
        pos[3] = s.find("BA", pos[2]+2);
        int n;// = pos[0]-pos[1];

        b=false;
        for(int i=0; i<2; i++){
            for(int j=3; j<4; j++){
                if(pos[i]==0 || pos[j]==0){
                    continue;
                }else{
                    n = pos[i]-pos[j];
                    if(n>=2 || n<=-2){
                        b=true;
                        break;
                    }
                }
                
            }
            if(b)break;
        }
        if(!b){
            printf("NO\n");
        }else{
            printf("YES\n");
            
        }
 //       cout<<pos1-pos2<<endl;
    }
    ~A550(){}

};

int main()
{
    A550 a550;
    return 0;
}