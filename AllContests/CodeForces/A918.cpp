#include <bits/stdc++.h>

using namespace std;


class A918{
private:
    int n, fn_1, fn_2,fn; 
    char *c;
public:
    A918(){
        scanf("%d",&n);
        c = new char[n+1];
        for(int i=0; i<n; i++){
            c[i] = 'o';
        }
        c[n]='\0';
        fn_1=1;fn_2=1;

        c[0]='O';
        fn=0;
        while(1){
            fn = fn_1 + fn_2;
            if(fn<=n){
                c[fn-1] = 'O';
                fn_2 = fn_1;
                fn_1 = fn;
            }else{ break; }
        }
        cout<<c<<endl;
    }
    ~A918(){}
};
int main()
{
    A918 a918;
    return 0;
}