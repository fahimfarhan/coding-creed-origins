#include <bits/stdc++.h>

using namespace std;

class A940{
private:
    int  n, d;
    int *a;
public:
    A940(){
        scanf("%d %d",&n,&d);
        a = new int[n];
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int result = 0;
        int temp=0;
        for(int i=0; i<n; i++){
            temp=0;
            for(int j=i+1; j<n; j++){
                
                if(a[j]-a[i]>d)break;
                temp = j-i; 
                //else{ temp++; }
            }
            result = max(result, temp);
            cout<<result<<endl;
        }

        printf("%d\n", result);

    }
    ~A940(){if(!a)delete[] a; }
};

int main()
{
    A940 a940;
    return 0;
}