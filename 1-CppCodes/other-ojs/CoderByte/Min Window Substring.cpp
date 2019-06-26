#include <bits/stdc++.h>
using namespace std;

string MinWindowSubstring(string strArr[]) { 

  // code goes here   
  string s1 = strArr[0]; 
  string s2 = strArr[1]; 
  
  int n = s1.size(); 
  int k = s2.size();
  
  bool mark[n];
  for(int i=0; i<n; i++){   mark[i] = false; }
  for(int i=0; i<k; i++){
      for(int j=0; j<n; j++){
          if(s2[i] == s1[j] ){  mark[j] = true;  }
      }
  }
  
  vector<int> v;
  for(int i=0; i<n;i++){    if(mark[i]){ v.push_back(i);  }  }
  
  string minimus = s1;
  
  for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++){
          string temp =s1.substr(i,j);
          string temp2 = temp; 
          bool b1 = true, b2 = false;
          for(int l=0; l<k; l++){
              if(!b1){ break; }
              b2 = false;
              for(int i1 = 0; i1 < temp.size(); i1++){
                  if(temp[i1] == s2[l]){
                      temp[i1] = 'A'; b2 = true; break;
                  }
              }
              if(b2 == false){ b1 = false; }
          }
          if(b1){ 
              // candidate found! 
              if(temp2.size() < minimus.size() ){ minimus = ""; minimus = temp2; }
              
          }
      }
  }
  
  return minimus; 
            
}

int main() { 
   
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  string A[] = gets(stdin);
  cout << MinWindowSubstring(A);
  return 0;
    
}
