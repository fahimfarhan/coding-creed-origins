## Definition
ETF of a number N is the number of positive integers that are coprime with N.

ETF(N) = # of pos integers coprime with N

phi(5) = 4 cz gcd(1,5) = gcd(2,5) = gcd(3,5) = gcd(4,5) = 1
phi(10) = 4 cz gcd(1,10) = gcd(3,10) = gcd(7,10) = gcd(9,10) = 1

## Bruteforce
```cpp
int phi(int N) {
  int count = 0;
  for(int i=1; i<N; i++) {
    if(__gcd(i,N) == 1) { count++;  }
  }
}

```
## Primes and Totient functions
## Some observations
phi(2) = 1
phi(3) = 2
phi(5) = 4
phi(7) = 6
phi(11) = 10
--- --- ---
--- --- ---
phi(P) = P-1 where P is a prime number.

## How to calc phi(P^x) , x > 1
phi(2^5) = phi(32) = 16

phi(P^x) = P^x - (number of integers not coprime with P)
         = P^x - (number of multiple of P)
         = P^x - (P^x / P)
         = P^x - P^x-1
         = (P-1)*P^x-1