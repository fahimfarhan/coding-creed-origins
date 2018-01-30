#include <bits/stdc++.h>

using namespace std;

class X{
public:
    int index, num;
    X() { index = 0;  num=0; };
};

bool compare(const X &a, const X &b) { return a.num < b.num; }

class A701{
private:
    int n;X *A;
public:
    A701(){
        scanf("%d",&n);
        A = new X[n];
        for(int i=0;i<n;i++){
            A[i].index=i+1;
        }
        for(int i=0; i<n;i++){
            scanf("%d",&A[i].num);
        }
        sort(A,A+n,compare);
        for(int i=0; i<n/2;i++){
            printf("%d %d\n",A[i].index, A[n-i-1].index);
        }

    }
    ~A701() {if(!A)delete[] A;}

   
};

int main()
{
    A701 a701;
    return 0;
}