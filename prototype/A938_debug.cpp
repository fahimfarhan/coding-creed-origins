#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define Min LLONG_MIN
bool ck(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    {
        return true;
    }
    else  return false;
}
int main()
{
    ll n,l,i,j=0;
    while(cin>>n){
    getchar();
   string s;
  getline(cin,s);
 //cin>>s;
 
   l= s.size();
 
    j=0;
   char str[1000];
 
    for(i=0; i<n-1; i++)
    {
        if(ck(s[i])==false)
        {
            str[j++] = s[i];
           
        }
 
        if(ck(s[i])==true && ck(s[i+1])==true)
        {
            s.erase(i+1,1);
            i--;
           
        }
        if(ck(s[i])==true)
        {
            str[j++] = s[i];
           //cout<<s[i];
        }
 
     
    }
   
    str[j]='\0';
    cout<<str;
         if(ck(s[n-1])==false) {//cout<<"Y";
          str[j+1]=s[n-1];
          cout<<s[n-1]<<endl;
         }
 
     s.clear();
 
    }
 
 
 
   return 0;
 
}
 