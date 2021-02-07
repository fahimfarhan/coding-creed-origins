## Multiplicative Functions
An arithmetic function is called multiplicative function if
```
    f(N*M) = f(N)*f(M) where gcd(N,M) = 1
```

Euler's totient function is a multiplicative function (a simple google search will give us the paper that proves it).
This means, 
     phi(N*M) = phi(N)*phi(M) where gcd(N,M) = 1

So if Q = NM = 20, N = 4, M = 5, then gcd(4,5) = 1. So phi(20) = phi(2^2)*phi(5) = 1 * 4 = 4

## Deriving the formula
N = P1^x1 * P2^x2 * P3^x3 ... Pm^xm

phi(N) = phi(P1^x1)*phi(P2^x2)*phi(P3^x3)*...*phi(Pm^xm)

But phi(P^x) = (P-1)*P^(x-1)

Therefore, phi(N) = (P1-1)*P1^(x1-1) *(P2-1)*P2^(x2-1) * (P3-1)*P3^(x3-1) *--- * (Pm-1)*Pm^(xm-1) --- --- ---(1)

Finding all the primes = O(sqrt(N))
Binary exp =             O(logN)

So current complexity = O(sqrt(N)logN)

How can we do better?
If we multiply numerator and denominator of RHS with P1*P2*P3*...*Pm, then,

    phi(N) = N *(P1-1)*(P2-1)*(P3-1)*...*(Pm-1) / (P1*P2*P3*...*Pm)

Since we no longer need to calc a^b, the bin exp is gone and so complexity = O(sqrt(N))

phi(6) = 6 phi(2-1)phi(3-1) / (2*3)
