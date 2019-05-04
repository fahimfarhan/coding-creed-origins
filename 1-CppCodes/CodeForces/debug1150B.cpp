#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define p pair<ll,ll>
#define fo(i,j,n)for(register ll i=j;i<n;i++)
const int N=1e5+10;
using namespace std;

int main()
{
   ll n;
   cin>>n;
   char s[54][54];
   ll ans=1;
   fo(i,0,n)
      fo(j,0,n)cin>>s[i][j];

   fo(i,1,n-1)
   {
       fo(j,0,n)
       {
           ll cnt=0;
           if(s[i][j]=='.')
           {
               ll J=j;
               ll got=0;
              while(s[i][J]=='.' && cnt<=3)
              {
                cnt++;
                if(cnt==3)break;
                J++;
              }

              if(cnt==3)
                {
                  if(s[i-1][J-1]=='.' && s[i+1][J-1]=='.')
                  {
                      fo(k,0,3)
                      {
                         s[i][k+j]='#';
                      }
                      s[i-1][J-1]='#';
                      s[i+1][J-1]='#';
                     got=1;
                  }
                }
              //if(got)j=J+1;
           }
       }
   }
     /* fo(i,0,n)
       {
           fo(j,0,n)cout<<s[i][j];
           cout<<"\n";
       }*/
       ans=1;
       fo(i,0,n)
       {
           fo(j,0,n)if(s[i][j]!='#')ans=0;
       }
       if(ans)cout<<"YES";
       else cout<<"NO";

        /*
        cout<<"\n\n";
       for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){  cout<<s[i][j]; } cout<<"\n";
       }*/
}