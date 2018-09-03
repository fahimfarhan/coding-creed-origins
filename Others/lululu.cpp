#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;

    string s,s1;

    for(int i=1;i<=t;i++)   {
        cin>>s;
        int l=s.size();

        for(int j=0;j<=l;j++)   {
            if(s[j]=='m' || s[j]=='n')  {
                s1.push_back(s[j]);
            }
        }
        cout<<s1<<endl;
    }
    return 0;
}