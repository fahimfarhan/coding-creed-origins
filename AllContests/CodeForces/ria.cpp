#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==0 || n==1 || n==2)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
        int sum = n/2;
        cout<<sum<<" ";
        int an = 2;
        for(int i=0;i<sum;i++)
        {
            cout<<an<<" ";
            an+=2;
        }
        cout<<endl;
        cout<<n-sum<<" ";
        an = 1;
        for(int i=0;i<n-sum;i++)
        {
            cout<<an<<" ";
            an+=2;
        }
    }

    return 0;
}