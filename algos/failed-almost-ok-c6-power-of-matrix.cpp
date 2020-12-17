#include<bits/stdc++.h>
#include <ios>
using namespace std;

#define ll long long
#define MOD 1000000007
            
inline void copyMatrix(ll** input,ll** output, ll dimen) {
  for(int i=0; i<dimen; i++) {
      for(int j=0; j<dimen; j++) {
        output[i][j] = input[i][j];
      }
    }
}


inline void matrixMultiply(ll** A, ll** B, ll dimen, ll** temp) {
  for(int i=0; i<dimen; i++) {
    for(int j=0; j<dimen; j++) {
      temp[i][j] = 0;
      for(int k=0; k<dimen; k++) {
        ll temp1 = ((A[i][k] * B[k][j]) % MOD);
        temp[i][j] = (temp[i][j] + temp1)%MOD; 
      }
    }
  }

  copyMatrix(temp, A, dimen);
}


inline void calcPowerOfMatrix(ll** input,ll** output, ll dimen, ll power,ll **temp) {
  if(power == 0) {
    return; // so output == identity matrix
  }
  if(power == 1) {
    copyMatrix(input, output, dimen);
    return;
  }

  ll p = power >> 1;
  calcPowerOfMatrix(input, output, dimen, p, temp); // output = input ^ p
  
  matrixMultiply(output, output, dimen, temp);

  if( (p&1) == 1) {
      matrixMultiply(output, input, dimen, temp);
  }
}

inline void printer(ll** input, ll dimen) {
  for(int i=0; i<dimen; i++) {
    for(int j=0; j<dimen; j++) {
      // input[i][j] *= 2;
      cout<<input[i][j]<<" ";
    }cout<<"\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll T, M, N;
  ll **input, **output, **temp;

  cin>>T;
  while(T--) {
    cin>>M>>N;
    input = new ll*[M];
    output = new ll*[M];
    temp = new ll*[M];
    for(int i=0; i<M; i++) 
    {  input[i] = new ll[M]; output[i] = new ll[M]; temp[i] = new ll[M]; }

    for(int i=0; i<M; i++) {
      for(int j=0; j<M; j++) {
        cin>>input[i][j];
      }
    }

    for(int i=0; i<M; i++) {
      for(int j=0; j<M; j++) {
        if(i == j) {  output[i][j] = 1; }
        else{ output[i][j] = 0; }
      }
    }

    calcPowerOfMatrix(input, output, M, N, temp);

    printer(output, M);

    for(int i=0; i<M; i++) { delete[] input[i]; delete[] output[i]; delete[] temp[i];  }
    delete[] input;
    delete[] output;
    delete[] temp;
  }
  
  return 0;
}