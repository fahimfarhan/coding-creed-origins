## Problem
Given Q queries about N , K, calculate C(N,K) % P where P>N
```
  nCr = n!/r!(n-r)!
  = (n-r+1)!/r!
```
Since   `a^m-2 == 1/a (mod m)` , therefore, 
so 1/r! == r!^p-2 (mod p)

So, 
```cpp
int nCr(int n, int r, int P) {
  int a = 1;
  for(int i=1; i<= n-r+1; i++) {
    a = (a * i) % P;
  }

  int b = 1;
  for(int i=1; i<= r; i++) {
    r = (r * i) % P;
  }

  int c = 1;
  for(int i=1; i<=P-2; i++) {
    c = (c * b) % P;
  }

  int ncr = a*c;
  return ncr;
}
```