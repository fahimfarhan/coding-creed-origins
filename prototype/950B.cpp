#include <bits/stdc++.h>

using namespace std;

class B950{
private:
    int *a,*b,i1,i2, l1,l2,s1,s2,count;
public:
    B950(){
        scanf("%d %d",&l1,&l2);
        a = new int[l1];
        b = new int[l2];
        //cout<<"ok1\n";
        s1=0; s2=0; count=0;

        for(int i=0; i<l1; i++){ scanf("%d",&a[i]); }
        for(int i=0; i<l2; i++){ scanf("%d",&b[i]); }
    
        i1=0,i2=0;
        //cout<<"ok2\n";
        while(i1<l1 || i2<l2){
            if(s1<s2){
                s1+=a[i1]; i1++;
            }else{
                s2+=b[i2]; i2++;
            }

            if(s1==s2){ count++;}
          //  cout<<"ok3 "<<count<<endl;
        }
        //cout<<"ok4\n";
        printf("%d\n",count);

    }
    ~B950(){
        if(!a)delete[] a;
        if(!b)delete[] b;
    }

};

int main()
{
    B950 b950;
    return 0;
}