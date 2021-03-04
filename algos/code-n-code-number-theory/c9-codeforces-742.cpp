#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

#define ll long long int

using namespace std;

inline int modularPower(int base, ll power, int mod) {
  if(power == 0) {  return 1; }
  if(power == 1) {  return base % mod; }
  ll p = power >> 1;
  ll output = modularPower(base, p, mod);
  output = output * output;
  if( (power & 1) == 1) {
    output = output * base;
  }
  output = output % mod;
  return output;
}

int main() {
  ll n;
  cin>>n;

  int mod = 10;
  ll output = modularPower(8, n, mod);
  // output = output % 10;
  cout<<output<<"\n";

  /**
  1378 ^ N mod 10 = (1000pN*1pN + 100pN*3pN + 10pN*7pN + 1pN*8pN) mod 10
                  == 8pN mod 10
   */
   // cout<<log2(1000000000);

  return 0;
}