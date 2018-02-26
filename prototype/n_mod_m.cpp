#include <bits/stdc++.h>
int g_count;
using namespace std;

int m_pow_x_mod_n(int m,int x,int n){
    if(x == 1){
        return m%n;
    }
    int x1 = x>>1;
    int x2 = x-x1;
    
    return (m_pow_x_mod_n(m,x1,n)*m_pow_x_mod_n(m,x2,n))%n;
}

int main()
{
clock_t tStart = clock();
       /* Do your stuff here */
       g_count=0;
       int a,b,c;
       cin>>a>>b>>c;

    int result = m_pow_x_mod_n(a,b,c);
    cout<<result<<endl;    printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}