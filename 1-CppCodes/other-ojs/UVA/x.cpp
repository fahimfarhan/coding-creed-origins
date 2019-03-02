#include<bits/stdc++.h>
using namespace std;
int main()
{
  int long_sentence=0;
  int num = 0; // I added this
  string s;
 vector<string>sentence;

 
 while(getline(cin,s))
 {
   sentence.push_back(s);
   if (sentence[num].size() > long_sentence)
   {
       long_sentence = sentence[num].size();
   }
   num++;
 }

 for (int i = 0; i < long_sentence; i++)
 {
     for(int j=0; j<num; j++){
         if(i<sentence[j].size()){
             cout<<sentence[i][j];
         }else{  cout<<" ";  }
     }
     cout<<"\n";
 }
 /*for(int i=0;i<num;i++)
 {
   for(int j=sentence.size()-1;j>0;j--)
   {
     if(sentence[j].size()>i)
     {
       cout<<sentence[j][i];
     }
     else
     {
       cout<<" ";
     }
   }
   cout<<endl;
 }*/
 return 0;
}