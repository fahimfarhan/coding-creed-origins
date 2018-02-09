#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n, k, count;

public:
    bool sumIs10(int x){
        int ans = 0;
        while(x){
            ans =ans+ x%10;
            x=x/10;
        }
        //cout<<ans<<endl;
        if(ans==10)return true;
        else return false;
    }
    Soln(){
        count = 0;
        n=10;
        scanf("%d",&k);
        //int loop = k;
        while(k>0){
            n+=9;//printf("%d", n);    
            if(sumIs10(n)){
                k--;
                
            }
            
        }
        printf("%d\n", n);
    }
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}