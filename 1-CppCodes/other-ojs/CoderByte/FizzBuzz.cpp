#include <iostream>
#include <string>
using namespace std;

int FizzBuzz(int num) { 

  // code goes here
  for(int i=1;i<=num; i++){
      
      if( ((i%3)==0) && ((i%5) == 0) ){ cout<<"FizzBuzz "; }
      else if( (i%3) == 0 ){ cout<<"Fizz "; } 
      else if( (i%5) == 0){ cout<<"Buzz "; }
      else{ cout<<i<<" "; }
  }cout<<"\n";
  return num; 
            
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
  
  // keep this function call here
  FizzBuzz(gets(stdin));
  return 0;
    
}
