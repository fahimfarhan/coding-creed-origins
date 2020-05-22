#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n, *a, start, end, index;
    string s;
public:
    void yo(){
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                start = i;
                int j=i+1;
                while(s[j]!='0' && j<s.length() ){
                    j++;
                }
                sort(a+i, a+j+1);
                i=j;
            }
        }
    }

    Soln(){
        cin>>n;
        a = new int[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        cin>>s;
        index = 0;
        yo();
        bool b = true;
        /*for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }cout<<endl;*/

        for(int i=1; i<n; i++){
            if(a[i]<a[i-1]){
                b = false; break;
            }
        }

        if(b){
            cout<<"YES\n";
        }else{cout<<"NO\n";}
    }
    ~Soln(){ if(!a)delete[] a;}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}