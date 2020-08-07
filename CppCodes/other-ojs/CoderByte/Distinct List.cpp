#include <bits/stdc++.h>
using namespace std;

int DistinctList(int a[], int n) { 
    int count=0;
    // code goes here   
  sort(a,a+n);
  
  int i=0,j=1;
  
  while(true){
      if( (i>=n) || (j>=n) ){ break; }
      if(a[i] == a[j] ){ count++; j++; }
      else{ i = j; j = j+1; }
      
  }
  
  return count; 
            
}

int main() { 
   
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  int A[] = gets(stdin);
  int n = sizeof(A)/sizeof(A[0]);
  
  //cout<<n<<"\n";
  cout << DistinctList(A,n);
  return 0;
    
}
