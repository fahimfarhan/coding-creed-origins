#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(int a){
    vector<int> v;
    while(a>0){
        int r = a%10;
        v.push_back(r);
        a=a/10;
    }
    int l = v.size();
    for(int i=0; i<l/2; i++){
        if(v[i]!=v[l-i-1]){
            return false;
        }
    }
    return true;
}
int main()
{
    clock_t begin = clock();
    
    int m,n,a;
    //m = 999; n = 999;
    //int a = m*n;
    //cout<<a<<"\n";
    int i,j;
    for(i=999; i>100; i--){
        for(j=999; j>100; j--){
            m=i; n=j;
            a = i*j;
            if(isPalindrome(a)){    break;  }
        }
    }
    cout<<a<<" "<<m<<" "<<n<<"\n";
    clock_t end = clock(); double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken is: %f\n", time_spent);
    
    return 0;
}