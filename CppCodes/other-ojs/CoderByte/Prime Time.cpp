#include <iostream>
#include <string>
using namespace std;

#define ll long long int 

bool *isPrime;
ll N;

void preprocess(){
    for(int i=0; i<=N; i++){ isPrime[i] = true; }    
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i=4; i<=N; i+=2){
        isPrime[i] = false;
    }
    
    for(int i=3; i<=N; i+=2){
        for(int j=i+i; j<=N; j+=i){
            isPrime[j] = false; 
        }
    }
}

string PrimeTime(int num) { 

    preprocess();
  // code goes here   
  if(isPrime[num]){ return "true";  }
  else{ return "false"; }
  // return num; 
            
}

int main() { 
  
  // keep this function call here
   N =1<<16;
  isPrime = new bool[N+1];
  
  cout << PrimeTime(gets(stdin));
  
  
  if(!isPrime)delete[] isPrime;
  return 0;
    
}
